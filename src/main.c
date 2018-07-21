#include <stdio.h>
#define GYRO_AND_ACCEL_MODE 1
int main(int argc, char *argv[])
{
	printf("Model Testing!\n");

	int res = 32;
	int sub = -32;

#if GYRO_MODE || \
	ACCEL_MODE || \
	GYRO_AND_ACCEL_MODE || \
	ACCEL_AND_GYRO_MODE
	
	printf("Result: %d[0x%x]\n", res - sub, res - sub);
#endif
	return 0;
}
