#pragma once
#include <string>
#include <fstream>

class CCsvMgr
{
   CCsvMgr();

   template <class T, class ... Ts>
   void PrintLine( T a, Ts&... args );

   template <class T>
   void PrintLine( T a);

private:
   // Directory of the file
   std::string m_szDir = "res/Results.csv";
   // Object for the document
   std::ofstream m_outdata;
};

// Print functions
template<class T, class ...Ts>
inline void CCsvMgr::PrintLine( T a, Ts& ...args ) {

   // Print the data without breakline
   m_outdata << a << ";";

   // Call the same function to print the other values
   PrintLine(args);
}

template<class T>
inline void CCsvMgr::PrintLine( T a ) {

   // Print the last value,
   // this will need a breakline
   m_outdata << a << ";" << std::endl;
}
