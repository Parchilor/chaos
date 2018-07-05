#include <stdio.h>
#include <pthread.h>

void *
Fun_player(void *data)
{
	int *j = (int *)data;
	for(int i = 0;i < 5;i++)
	{
		printf("%d ---> %d\n", i, (*j)++);
	}
	return NULL;
}

int
main(int argc, char *argv[])
{
	pthread_t pid;
	int i = 10;
	for(int j; j < 3; j++) {
		pthread_create(&pid, NULL, Fun_player, &i);
		printf("%d\n", j);
		pthread_join(pid, NULL);
	}
	return 0;
}
