#include "palindromic.h"

// Macro to iterate vector backwards
#define CEIL_DIVISION(_x,_y) ( (_x) / (_y) + ( (_x) % (_y) != 0) )


CPalindromic::CPalindromic( int nBase ) {
   m_nBase = nBase;
}

bool
CPalindromic::GetUnderValue( int nMaxValue ) {

   // Check the upper value and the base
   if ( nMaxValue < 1 || m_nBase < 2 )
      return false;

   // Compute how many digits has the maximum value
   int nMaxDigits = log( nMaxValue ) / log( m_nBase ) + 0.01;

   // Loop through the lengths
   for ( int i = 1; i <= nMaxDigits; i++ ) {
      std::vector<int> vtCurrLen;
      GetValuesWithLen( i, &vtCurrLen );

      m_vtPalindromics.insert( m_vtPalindromics.end(), vtCurrLen.begin(), vtCurrLen.end() );
   }

   return true;
}

bool
CPalindromic::GetValuesWithLen( const int& nLen, std::vector<int>* vtPalindromics ) {

   // Get how many free digits I have
   int nFreedom = CEIL_DIVISION( nLen, 2 );
   int nTotal = pow( m_nBase, nFreedom );

   // Iteration th quantity of numbers I know I'll get
   for ( int i = 1; i < nTotal; i++ ) {
      int nCurr;
      // Compute the current number
      if ( MakePalindromic( nLen, i, &nCurr ) )
         // Add the number to the vector
         vtPalindromics->push_back( nCurr );
   }

   return true;
}

int
CPalindromic::MakePalindromic( const int& nLen, const int& nNum, int* nPalindromic ) {

   // The introduced number are the right digits
   // I have to invert them and append them at the right
   std::vector<int> vtDigits;
   ConvertToBasis( nNum, &vtDigits );

   // If the first digit is 0, i cannot make the palindromic
   if ( !vtDigits[0] )
      return false;

   // If the length of the number if odd, there is a digit that does not repeat
   if ( nLen % 2 &&
        vtDigits.size() * 2 == nLen + 1 )
      vtDigits.pop_back();

   // To the introduced number a have to add the inverse number
   int nResult = nNum;
   int nCurrExp = nLen - 1;
   // Loop through the digits, starting backwards
   for ( auto i : vtDigits ) {
      nResult += i * pow( m_nBase, nCurrExp );

      nCurrExp--;
   }

   if ( nPalindromic )
      *nPalindromic = nResult;

   return true;
}

bool
CPalindromic::ConvertToBasis( int nNum, std::vector<int>* vtDigits ) {

   // Create the list of digits
   while ( nNum ) {
      vtDigits->push_back( nNum % m_nBase );
      nNum /= m_nBase;
   }

   return true;
}

