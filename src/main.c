#include <stdio.h>

#define _BIT 16

unsigned long int data_width(unsigned long int bit)
{
	if(bit == 0)
		return 0;
	unsigned long int i, sum = 1;
	for(i = 0; i < bit; i++)
	{
		sum *= 2;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	printf("Model Testing!\n");

	printf("%d-bit Maximum Decimalism: %lu\n", _BIT, data_width(_BIT));
	return 0;
}
