#include <stdio.h>

extern int i;
void _extern(void)
{
	printf("%s i = %d\n", __FILE__, i++);
}
