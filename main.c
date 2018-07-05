#include <stdio.h>
#include "test.h"
//extern int i;
int i = 10;
int
main(int argc, char *argv[])
{
	for(int j = 15; j > 0 ;j--) {
		printf("%s i = %d\n", __FILE__, i++);
		_extern();
	}
	return 0;
}
