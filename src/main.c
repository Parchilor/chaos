#include "c_inc.h"

int
main (int argc, char *argv[])
{
	union check	{
		int i;
		char ch;
	}c;
	c.i = 1;
	if (c.ch == 1)	{
		printf("System is \033[31m\033[1mlittle endian\033[0m.\n");
	}	else	{
		printf("System is \033[31m\033[1mbig endian\033[0m .\n");
	}
	return 0;
}
