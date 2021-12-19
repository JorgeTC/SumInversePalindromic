#pragma once
#include <vector>

class CPalindromic;

class CInverseSum
{
public:
   CInverseSum( std::vector<int>* ptToSum );
   CInverseSum( CPalindromic &palin );

   double GetResult();
private:
   std::vector<int>* m_pvtToSum;
   double m_dResult{ 0.0 };
};

