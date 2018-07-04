#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/utsname.h>

#define _print(x) printf("test_"#x" --> %d\n", test_##x)
int
main (int argc, char *argv[])
{
	printf ("Testing!\n");
	printf("int max: %s\n", STR(TEST));
	return 0;
}
