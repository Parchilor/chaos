#include "c_inc.h"

int 
main (int argc, char *argv[])
{
	time_t t;
	struct tm *tmp;
	char buf1[16], buf2[64];
	time (&t);
	tmp = localtime (&t);
	if (strftime (buf1, 16, "%X, %a %b %d, %Y", tmp) == 0)	{
		printf ("Buffer length 16 is too small\n");
	}	else	{
		printf ("%s\n", buf1);
	}

	if (strftime (buf2, 64, "%X, %a %b %d, %Y", tmp) == 0)	{
		printf ("Buffer length 64 is too small\n");
	}	else	{
		printf("%s\n", buf2);
	}
	return 0;
}
