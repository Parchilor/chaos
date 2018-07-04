#include <string.h>
#include <stdio.h>

#include "fs.h"
#include "sys.h"
#include "encode.h"
#include "decode.h"
#include "struct.h"
#include "cJSON.h"

int main (int argc, char *argv[])
{
	printf ("Module: Testing!\n");
	readCMD();
	cjson2struct();
	option();
	pMember();
	return 0;
}
