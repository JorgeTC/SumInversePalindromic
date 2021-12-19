#pragma once
#include <vector>

class CInverseSum
{
public:
   CInverseSum( std::vector<int>* ptToSum );

   double GetResult();
private:
   std::vector<int>* m_pvtToSum;
   double m_dResult;
};

