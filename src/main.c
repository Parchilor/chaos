#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/utsname.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

void print(char **str)
{
	printf("str: %s %s\n", *str, *(str+1));
}

int
main(int argc, char *argv[])
{
	printf ("\nParchilor$ ");
	char *str[] = {"Playback","190"};
	char str1[16];
	sprintf(str1, "%d", 220);
	*(str+1) = str1;
	print(str);
	return 0;
}
