#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/utsname.h>

/*
 * void va_start(va_list ap, last);
 * type va_arg(va_list ap, type);
 * void va_end(va_list ap);
 * void va_copy(va_list dest, va_list src);
 */
/*
void
foo(int cnt, ...)
{
	int i;
	char *tmp;
	va_list ap;
	va_start(ap, NULL);
	for(i = 0; i < cnt; i++)
	{
		tmp = va_arg(ap, char *);
		printf("%s\n", tmp);
	}
	va_end(ap);
}

int
main (int argc, char *argv[])
{
	printf ("Testing!\n");
	foo(4, "Type", "Company", "Version", "Price");
	return 0;
}
*/
int hal_trace(const char* fmt, ...)
{
	va_list args;
	int len;
	char buff[128];

	va_start(args, fmt);
	len = vsnprintf(buff, sizeof(buff)-1, fmt, args);
	va_end(args);

	buff[len] = 0;
	printf("%s",buff);
	return len;
}

int main(int argc, char *argv[])
{
	printf("HAL_TRACE :%d\n", hal_trace("%s : %s\n", "help", "show this message"));
	return 0;
}
