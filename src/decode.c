#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "cJSON.h"

void cjson2struct(void)
{
	cJSON *root, *temp;
	char *out;

	root = cJSON_Parse(CTRL_getCMD());

	temp = cJSON_GetObjectItem(root, "action");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setAction(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "mib");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setMib(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "var");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setVar(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "ip");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setIp(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "nodeaddress");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setNodeaddress(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "token");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setToken(out, strlen(out) + 1);
	}
	
	temp = cJSON_GetObjectItem(root, "address");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setBRaddress(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "Scene");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setScene(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "name");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setName(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "key");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setKey(out, strlen(out) + 1);
	}

	temp = cJSON_GetObjectItem(root, "value");
	out = cJSON_PrintUnformatted(temp);
	if(out != NULL)
	{
		out = &out[1];
		out[strlen(out) - 1] = '\0';
		CTRL_setValue(out, strlen(out) + 1);
	}
}
