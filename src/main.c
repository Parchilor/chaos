#include <stdio.h>

#define STR(n) (#n)
#define CONS(a, b) (a##b)

int main(int argc, char *argv[])
{
	printf("%s->%ld\n", STR(char), sizeof(char));
	printf("%s->%ld\n", STR(short int), sizeof(short int));
	printf("%s->%ld\n", STR(int), sizeof(int));
	printf("%s->%ld\n", STR(long int), sizeof(long int));
	printf("%s->%ld\n", STR(double), sizeof(double));

	return 0;
}
