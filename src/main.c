#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char* list[] = {"Tom","Andy","Android","IOS","Python","No Lock","Unsigend","Blog","Random","Tonny"};

int main()
{
	int i;
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		printf("Random Output : %s\n", list[rand() % 10]);
	}
	return 0;
}

