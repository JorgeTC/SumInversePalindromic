#include "CsvMgr.h"

CCsvMgr::CCsvMgr() {

   m_outdata.open( m_szDir );
}

CCsvMgr::~CCsvMgr() {
   m_outdata.close();
}
