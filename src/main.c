#include "c_inc.h"

struct dat{
	u8 func1;
	u8 func2;
	u8 *data;
};

int
main (int argc, char *argv[])
{
	u8 data[] = {0x03, 0x0E, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
	struct dat tmp;
	tmp.func1 = data[0];
	tmp.func2 = data[1];
	tmp.data = &data[2];

	printf("Func1: 0x%.2x, Func2: 0x%.2x\n", tmp.func1, tmp.func2);
	u8 i;
	for(i = 0; i < strlen(tmp.data); i++){
		printf("data[%d]: 0x%.2x ", i, tmp.data[i]);
		fflush(stdout);
	}
	putchar('\n');
	printf("Pass\n");
	return 0;
}

