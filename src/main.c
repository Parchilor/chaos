#include <stdio.h>
#include <string.h>
#include "sqlopt.h"

// Data struct
struct mydata {
	char type[64];
	char company[256];
	char version[128];
	float price;
};

// SQL callback
int
callback(void *data, int argc, char **argv, char **azColName)  
{
	int i;
   	fprintf(stderr, "%s: ", (const char *)data);
	for(i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
sqlopt opt = {
	SQL_FILE_INIT("test.db"),
	SQL_EXEC_INIT(callback, NULL),
};

/*
sqlopt opt = {
	.filename = "test.db",
};
*/

int main()  
{
	SQL_Open(opt);
	SQL_EXEC_COMMAND(opt, "create table test(Type text, Company text, Version text, Price real);");
	SQL_Exec(opt);
	SQL_EXEC_COMMAND(opt, "insert into test values('DSLR', 'Nikon', 'D5500', 3699);");
	SQL_Exec(opt);
	SQL_Close(opt);
	return 0;  
}  
