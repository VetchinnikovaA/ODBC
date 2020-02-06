#include <odbcinst.h>
#include <Windows.h>

SQLHENV henv;
SQLHDBC hdbc;
SQLHSTMT hstmt;
SQLRETURN retcode;
SQLCHAR      buf[50];	
SQLINTEGER buf_len;

retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
