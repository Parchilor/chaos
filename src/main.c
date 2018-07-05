#include "c_inc.h"

int
main (int argc, char *argv[])
{
	char name[64];
	gethostname (name , sizeof (name));
	printf("%s\n", name);
	return 0;
}
