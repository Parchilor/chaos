#include <string.h>
#include <stdio.h>

#include "fs.h"
#include "encode.h"
#include "decode.h"
#include "struct.h"
#include "cJSON.h"

#define opt_nu 11
char *opt[opt_nu] = {
	"Login",
	"Logout",
	"Password",
	"discover",
	"SetVar",
	"GetVar"
};

void option(void)
{
	int i;
	char *act = CTRL_getAction();
	char *mib = CTRL_getMib();
	char *var = CTRL_getVar();
	// reflash node
	// nodeaddress to u64x
	// value to u8x
	/*	
	if(strncmp(CTRL_getBRaddress(), ipv6, 32))
	{
		return ;
	}
	*/
	for(i = 0; i < opt_nu; i++)
	{
//		if(!strncmp(act, opt[i], strlen(opt[i])))
			break;
	}
	switch(i)
	{
		case 1:
//			user_login();
			break;
		case 2:
//			user_logout();
			break;
		case 3:
//			pwmng();
			break;
		case 4:
//			discover();
			break;
		case 5:

			break;
		case 6:
			break;
		default:
			break;
	}
}
