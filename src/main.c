#include <time.h>
//#include <errno.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int main(argc, argv)
	int argc;
	char *argv[];
{
	time_t t;
	struct tm *tm;
	time(&t);
	tm = gmtime(&t);
	printf("%.4d/%.2d/%.2d %.2d:%.2d:%.2d\n", 
			1900+tm->tm_year, 
			tm->tm_mon+1, 
			tm->tm_mday, 
			tm->tm_hour > 15?(tm->tm_hour - 16):(tm->tm_hour+8), 
			tm->tm_min, 
			tm->tm_sec);
}
