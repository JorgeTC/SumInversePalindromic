#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

class CCsvMgr
{
public:
   CCsvMgr();
   ~CCsvMgr();

   template <class T, class ... Ts>
   bool PrintLine( T a, Ts&... args );

   template <class T>
   bool PrintLine( T a);

private:
   // Directory of the file
   std::string m_szDir = "res/Results.csv";
   // Object for the document
   std::ofstream m_outdata;
};

// Print functions
template<class T, class ...Ts>
inline bool CCsvMgr::PrintLine( T a, Ts& ...args ) {

   // Print the data without breakline
   m_outdata << std::fixed << std::setprecision( 8 ) << a << ";";

   // Call the same function to print the other values
   return PrintLine( args... );
}

template<class T>
inline bool CCsvMgr::PrintLine( T a ) {

   if ( !m_outdata ) {
      std::cout << "Impossible to write in csv file.\n";
      return false;
   }

   // Print the last value,
   // this will need a breakline
   m_outdata << std::fixed << std::setprecision( 8 ) << a << std::endl;
}
