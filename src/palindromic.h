#pragma once

#include <vector>

class CPalindromic
{
   public:
   // Constructor
   CPalindromic( int nBase );

   // Compute the list
   bool GetUnderValue( int nMaxValue );
   // Getter
   std::vector<int>* GetVector() { return &m_vtPalindromics; };
   double GetInversesumValue();

   private:

   bool GetValuesWithLen( const int& nLen, std::vector<int>* vtPalindromics );
   int  MakePalindromic( const int& nLen, const int& nNum, int* nPalindromic );
   bool ConvertToBasis( int nNum, std::vector<int>* vtDigits );

   private:
   int m_nBase;
   std::vector<int> m_vtPalindromics;
};

