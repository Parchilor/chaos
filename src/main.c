#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static inline void
get_cpuid(unsigned int i, unsigned int *buf)
{
	unsigned int eax, ebx, ecx, edx;
//	__asm__(
	asm(
			"cpuid"
			:"=a"(eax),"=b"(ebx),"=c"(ecx),"=d"(edx):"a"(i)
	   );
//														 );
	buf[0] = eax;
	buf[1] = ebx;
	buf[2] = ecx;
	buf[3] = edx;
}
  
int main(void)
{
	unsigned int cpu[4], i;
	get_cpuid(0, cpu);
	printf("CPU Vender ID: ");
	for(i = 0; i < 4; i++)
	{
		printf("0x%x ",cpu[i]);
	}
	putchar('\n');
	return 0;
}
