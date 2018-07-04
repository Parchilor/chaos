#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "cJSON.h"
void readCMD(void)
{
	int len = 0;
	char cmd[CMD_SIZE];
	FILE *fp = fopen(rPATH, "r");
	if(fp == NULL)
	{
		printf("%s opened fail!\n", rPATH);
		return;
	}
	fread(cmd, CMD_SIZE, 1, fp);
	fclose(fp);
	len = strlen(cmd);
	CTRL_setCMD(cmd, len);
}

void pMember(void)
{
	printf("Action: %s\n"
			"Mib: %s\n"
			"Var: %s\n"
			"Ip: %s\n"
			"BRaddress: %s\n"
			"Name: %s\n"
			"Key: %s\n"
			"Nodeaddress: %s\n"
			"Value: %s\n"
			"Scene: %s\n"
			"Token: %s\n",
			CTRL_getAction(),
			CTRL_getMib(),
			CTRL_getVar(),
			CTRL_getIp(),
			CTRL_getBRaddress(),
			CTRL_getName(),
			CTRL_getKey(),
			CTRL_getNodeaddress(),
			CTRL_getValue(),
			CTRL_getScene(),
			CTRL_getToken()
			);
}
