#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Testing!\n");
	char *srcarr[4] = {
		"East",
		"West",
		"North",
		"South"
	};
	int i;
	for(i = 0; i < 4; i++)
	{
		printf("%s\n", srcarr[i]);
	}
	return 0;
}
