#include "InverseSum.h"

CInverseSum::CInverseSum( std::vector<int>* ptToSum ) {
   m_pvtToSum = ptToSum;
}

double
CInverseSum::GetResult() {

   // Reset the result
   m_dResult = 0.0;
   
   // Compute the sume of the inverses
   for ( auto nNum : *m_pvtToSum ) {
      m_dResult += 1 / nNum;
   }

   return m_dResult;
}
