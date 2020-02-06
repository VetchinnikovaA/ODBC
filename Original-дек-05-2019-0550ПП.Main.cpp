#include "classSQL.h"

int initConnection()
{
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if (retcode < 0)
		return -1;
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, SQL_NTS);
	if (retcode < 0)
		return -2;
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	if (retcode < 0)
		return -3;
	retcode = SQLConnect(hdbc, (SQLWCHAR*)L"lavka", SQL_NTS,
		(SQLWCHAR*)L"lavka_admin", SQL_NTS, (SQLWCHAR*)L"admin", SQL_NTS);
	if (retcode < 0) {

		SQLWCHAR sqlstate[1024];
		SQLWCHAR sqlstate2[1024];
		SQLINTEGER sqlinteger;
		SQLSMALLINT sqlsamllint;

		cout<<SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, 1, sqlstate, &sqlinteger, sqlstate2, 1024, &sqlsamllint)<<endl;
		cout<<sqlstate<<endl;
		cout<<sqlstate2 << endl;

		return retcode;
	}
	if (retcode < 0)
		return -4;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode < 0)
		return -5;
	return 0;
}

int initTable()
{
	int result = 0;
	result = SQLExecDirect(hstmt, (SQLWCHAR*)L"CREATE TABLE IF NOT EXISTS prot\
		(\
		id serial primary key ,\
		name varchar not null,\
		price int not null,\
		type_id int not null,\
		color_id int not null,\
		size_id int not null)\; ", SQL_NTS);
	if (result < 0)
		return -1;
	/*result = SQLExecDirect(hstmt, (SQLWCHAR*)L"CREATE TABLE IF NOT EXISTS p\
		(\
		imya character varying,\
		adres character varying,\
		familiya character varying,\
		otchestvo character varying,\
		id integer NOT NULL,\
		CONSTRAINT pk_id PRIMARY KEY(id)\
		)\
		WITH(\
		OIDS = FALSE\
		);\
	ALTER TABLE persons\
		OWNER TO silofed; ", SQL_NTS);
	if (result < 0)
		return -2;
	result = SQLExecDirect(hstmt, (SQLWCHAR*)L"CREATE TABLE IF NOT EXISTS types\
		(\
		id integer NOT NULL,\
		type character varying,\
		CONSTRAINT pk_type PRIMARY KEY(id)\
		)\
		WITH(\
		OIDS = FALSE\
		);\
	ALTER TABLE types\
		OWNER TO silofed; ", SQL_NTS);
	if (result < 0)
		return -3;|*/
	return 0;
}

void main()
{
	cout << initConnection() << endl;
	// ÏÎÄÊËÞ×ÈËÈÑÜ
	cout << initTable() << endl;
	// ÐÀÁÎÒÀÅÌ
	//retcode = SQLExecDirect(hstmt, (SQLWCHAR*)L"CREATE TABLE IF NOT EXISTS tabl1 ( alya int, blya int, clya int )", SQL_NTS);
//	cout << "step 6=" << retcode << endl;
	//retcode = SQLFetch(hstmt);
	//cout << "step 7=" << retcode << endl;
	//SQLGetData(hstmt, 1, SQL_C_CHAR, buf, 50, &buf_len);
//	cout << buf << endl;
//	Phone t;
	//t.show();
	system("pause");
}