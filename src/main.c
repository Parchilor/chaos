#include "c_inc.h"

u8 data[] = {0x7E, 0x0C, 0x03, 0x0E, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0A, 0x7F};

int
main (int argc, char *argv[])
{
	u16 pkgsiz = sizeof(data);
	u16 pkglen = pkgsiz/sizeof(u8);
	u16 datlen = data[1];

	u8 temp = 0;
	u8 offset = 2;

	if (data[0] != 0x7e)	{
		printf ("%s: Fail! --> [Head]\n", __func__);
		return EAGAIN;
	}

	if (data[pkglen - 1] != 0x7f)	{
		printf ("%s: Fail! --> [Tail]\n", __func__);
		return EAGAIN;
	}	

	if (data[1] == 0x7d)  {
		switch (data[2]){
			case 0x01:
				datlen = 0x7d;
				break;
			case 0x02:
				datlen = 0x7e;
				break;
			case 0x03:
				datlen = 0x7f;
				break;
		}
		offset = 3;
	}

	printf("datlen: 0x%.2x, offset: %d\n", datlen, offset);
	/* Verify */
	for (u8 i = 1; i < datlen + offset; i++)	{
		temp ^= data[i];
	}

	u8 ret[datlen];
	for (int i = 0; i < datlen; i++)	{
		ret[i] = data[i+offset];
		printf("ret[%d] 0x%.2x ", i, ret[i]);
		fflush(stdout);
	}
	printf("retlen: %ld\n", sizeof(ret)/sizeof(u8));
#if 0

	u8 ret[pkglen-2];

	ret[0] = data[1];
	for (int i = 1; i < pkglen - 2; i++)	{
		ret[i] = data[i+1];
	}
	for (int i = 0; i < pkglen; i++)	{
		printf("Ret: 0x%.2x  Data: 0x%.2x\n", ret[i], data[i]);
	}
	u8 temp = 0;
	u16 i;
	for (i = 1; i < data[1] + 1 + 1; i++)	{
		temp ^= data[i];
		printf("0x%.2x ", data[i]);
	}
	putchar('\n');
	printf("i: %d, Verify: 0x%.2x, Data[i]: 0x%.2x\n", i, temp, data[i]);
#endif
	return 0;
}

