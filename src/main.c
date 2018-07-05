#include "c_inc.h"
#include <errno.h>

typedef unsigned char u8;
typedef unsigned short u16;

u8 data[] = {0x7E, 0x0C, 0x03, 0x0E, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0A, 0x7F};

struct ttydat {
	u8 dlen;
	u8 *data;
};

u8
*tty_revc()
{	
	u16	datlen = data[1];
	u16	pkgsiz = sizeof(data);
	u16	pkglen = pkgsiz/sizeof(u8);

	u8 verify = 0;
	u8 offset = 2;
	u8 i;

	if (data[0] != 0x7e)	{
		printf ("%s: Fail! --> [Head]\n", __func__);
		return NULL;
	}

	if (data[pkglen - 1] != 0x7f)	{
		printf ("%s: Fail! --> [Tail]\n", __func__);
		return NULL;
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

//	offset + datlen = Verify bit
	/* Verify */
	for (i = 1; i < datlen + offset; i++)	{
		verify ^= data[i];
	}
//	printf("Verify: 0x%x, data[]: 0x%x\n", verify, data[offset+datlen]);
	if(verify != data[offset + datlen]) {
		printf ("%s: Fail! --> [Verify]\n", __func__);
		return NULL;
	}
	u8 *ret = malloc(sizeof(u8) * (datlen+1));
	ret[0] = datlen;

	for (i = 1; i < datlen+1; i++)	{
		ret[i] = data[i+offset-1];
	}

	return ret;
}


int
main (int argc, char *argv[])
{
	u8 *test = tty_revc(), i;
	if(test == NULL) {
		printf("Error!\n");
		return -1;
	}

	struct ttydat dat;
	dat.dlen = test[0];
	dat.data = &test[1];

	printf("Data length: 0x%x\n", dat.dlen);
	printf("Data: ");
	for(i = 0; i < dat.dlen; i++)	{
		printf("0x%.2x ", dat.data[i]);
		if(i%5 == 4) {
			putchar('\n');
		}
	}

#if 0
	for(i = 0; i < test[0]+1; i++){
		printf("test[%d]--> 0x%.2x ", i, test[i]);
		if(i%5 == 4) {
			putchar('\n');
		}
		fflush(stdout);
	}
#endif
	putchar('\n');
	FILE * fp = fopen("./test.log", "w");
	while(1);
	return 0;
}
