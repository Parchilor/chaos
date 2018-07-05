#include "c_inc.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

struct len{
	u8 x1;
	u8 x2;
	u8 x3;
	u8 x4;
	u8 x5;
	u8 x6;
	u8 x7;
	u8 x8;
};

u8 str[8];

int
main (int argc, char *argv[])
{
	u64 i = 0x12345678;
	printf("address: 0x%x -> 0x%.4x\n", &i, i);
	struct len *j = (struct length*)&i;
	printf("0x%x\t0x%x\t0x%x\t0x%x\t0x%x\t0x%x\t0x%x\t0x%x\n", 
			&(j->x1), &(j->x2), &(j->x3), &(j->x4), &(j->x5), &(j->x6), &(j->x7), &(j->x8));
	putchar('\n');
	printf("x1: 0x%x, x2: 0x%x, x3: 0x%x, x4: 0x%x, x5: 0x%x, x6: 0x%x, x7: 0x%x, x8: 0x%x\n", 
			j->x1, j->x2, j->x3, j->x4, j->x5, j->x6, j->x7, j->x8);
	return 0;
}
