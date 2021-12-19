#include "InverseSum.h"
#include "palindromic.h"

CInverseSum::CInverseSum( std::vector<int>* ptToSum ) {
   m_pvtToSum = ptToSum;
}

CInverseSum::CInverseSum( CPalindromic &palin ) {
   m_pvtToSum = palin.GetVector();
}

double
CInverseSum::GetResult() {

   // Reset the result
   m_dResult = 0.0;
   
   // Compute the sume of the inverses
   for ( auto nNum : *m_pvtToSum ) {
      m_dResult += 1 / double( nNum );
   }

   return m_dResult;
}
