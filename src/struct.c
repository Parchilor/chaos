#include <string.h>
#include <stdlib.h>
#include "struct.h"

static st_cmd_t st_cmd;

void CTRL_setAction(char *data, int n)
{
	strncpy(st_cmd.pcmd.action, data, n);
}

void CTRL_setMib(char *data, int n)
{
	strncpy(st_cmd.pcmd.mib, data, n);
}

void CTRL_setVar(char *data, int n)
{
	strncpy(st_cmd.pcmd.var, data, n);
}

void CTRL_setIp(char *data, int n)
{
	strncpy(st_cmd.ipv4, data, n);
}

void CTRL_setBRaddress(char *data, int n)
{
	strncpy(st_cmd.ipv6, data, n);
}

void CTRL_setToken(char *data, int n)
{
	strncpy(st_cmd.token, data, n);
}

void CTRL_setName(char *data, int n)
{
	strncpy(st_cmd.id, data, n);
}

void CTRL_setKey(char *data, int n)
{
	strncpy(st_cmd.pw, data, n);
}

void CTRL_setNodeaddress(char *data, int n)
{
	strncpy(st_cmd.devid, data, n);
}

void CTRL_setValue(char *data, int n)
{
	strncpy(st_cmd.value, data, n);
}

void CTRL_setScene(char *data, int n)
{
	strncpy(st_cmd.scene, data, n);
}

char *CTRL_getAction(void)
{
	return st_cmd.pcmd.action;
}

char *CTRL_getMib(void)
{
	return st_cmd.pcmd.mib;
}

char *CTRL_getVar(void)
{
	return st_cmd.pcmd.var;
}

char *CTRL_getIp(void)
{
	return st_cmd.ipv4;
}

char *CTRL_getBRaddress(void)
{
	return st_cmd.ipv6;
}

char *CTRL_getToken(void)
{
	return st_cmd.token;
}

char *CTRL_getName(void)
{
	return st_cmd.id;
}

char *CTRL_getKey(void)
{
	return st_cmd.pw;
}

char *CTRL_getNodeaddress(void)
{
	return st_cmd.devid;
}

char *CTRL_getValue(void)
{
	return st_cmd.value;
}

char *CTRL_getScene(void)
{
	return st_cmd.scene;
}

static st_jscmd_t scmd;
void CTRL_setCMD(char *data, int n)
{
	strncpy(scmd.cmd, data, n);
	scmd.len = n;
}

char *CTRL_getCMD(void)
{
	return scmd.cmd;
}

int CTRL_getCMDLEN(void)
{
	return scmd.len;
}

static st_ret_t sret;
void CTRL_RET_init(void)
{
	sret.ret = malloc(sizeof(char) * RET_SIZE);
}

void CTRL_RET_destroy(void) 
{
	free(sret.ret);
	sret.len = 0;
}

void CTRL_setRET(char *data, int n)
{
	strncpy(sret.ret, data, n);
	sret.len = n;
}

char *CTRL_getRET(void)
{
	return sret.ret;
}

int CTRL_getRETLEN(void)
{
	return sret.len;
}

