#include <stdio.h>

typedef struct {
	unsigned char a:5;
	unsigned char b:3;
	unsigned char c:1;
	unsigned char d:7;
	unsigned char e:2;
} _BIT;

#define STR(n) (#n)

int main(int argc, char *argv[])
{
//	_BIT arg = {0xff, 0xff, 0xff, 0xff, 0xff};
	_BIT arg = {0x00, 0x00, 0x00, 0x00, 0x00};

	printf("The struct size: _%s ---> %ld\n\n", STR(_BIT), sizeof(_BIT));

	printf("Store: %s ---> %d[0x%x]\n", STR(a), arg.a, arg.a);
	printf("Store: %s ---> %d[0x%x]\n", STR(b), arg.b, arg.b);
	printf("Store: %s ---> %d[0x%x]\n", STR(c), arg.c, arg.c);
	printf("Store: %s ---> %d[0x%x]\n", STR(d), arg.d, arg.d);
	printf("Store: %s ---> %d[0x%x]\n", STR(e), arg.e, arg.e);

	arg.c = 0xff;

	printf("Store: %s ---> %d[0x%x]\n", STR(a), arg.a, arg.a);
	printf("Store: %s ---> %d[0x%x]\n", STR(b), arg.b, arg.b);
	printf("Store: %s ---> %d[0x%x]\n", STR(c), arg.c, arg.c);
	printf("Store: %s ---> %d[0x%x]\n", STR(d), arg.d, arg.d);
	printf("Store: %s ---> %d[0x%x]\n", STR(e), arg.e, arg.e);
	return 0;
}
