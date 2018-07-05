#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/utsname.h>

#include "type.h"
static DEV_INFO board_info[] = {
	{DEV_ADD_INFO("Sony", "NW-ZX100", 0x01),},
};

int
main (int argc, char *argv[])
{
	printf("Company: %s, Type: %s, ID: 0x%.2x\n", board_info[0].company, board_info[0].type, board_info[0].id);
	return 0;
}
