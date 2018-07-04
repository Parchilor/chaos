#pragma once

#define rPATH "files/cmd"
#define CMD_SIZE 256
#define RET_SIZE 1024
//static char *ipv6 = "fd04:bd3:80e8:2:215:8d00:5d:53b0";

typedef struct {
	char action[16];
	char mib[16];
	char var[16];
} pCMD;

typedef struct {
	pCMD pcmd;
	char ipv4[32];
	char ipv6[64];
	char token[32];
	char id[64];
	char pw[64];
	char devid[32];
	char value[64];
	char scene[64];
} st_cmd_t;

typedef struct {
	char cmd[CMD_SIZE];
	int len;
} st_jscmd_t;

typedef struct {
	char *ret;
	int len;
} st_ret_t;

void CTRL_setAction(char *, int);
void CTRL_setMib(char *, int);
void CTRL_setVar(char *, int);
void CTRL_setIp(char *, int);
void CTRL_setBRaddress(char *, int);
void CTRL_setToken(char *, int);
void CTRL_setName(char *, int);
void CTRL_setKey(char *, int);
void CTRL_setNodeaddress(char *, int);
void CTRL_setValue(char *, int);
void CTRL_setScene(char *, int);

char *CTRL_getAction(void);
char *CTRL_getMib(void);
char *CTRL_getVar(void);
char *CTRL_getIp(void);
char *CTRL_getBRaddress(void);
char *CTRL_getToken(void);
char *CTRL_getName(void);
char *CTRL_getKey(void);
char *CTRL_getNodeaddress(void);
char *CTRL_getValue(void);
char *CTRL_getScene(void);

void CTRL_setCMD(char *, int);
char *CTRL_getCMD(void);
int CTRL_getCMDLEN(void);

void CTRL_RET_init(void);
void CTRL_RET_destroy(void);
void CTRL_setRET(char *, int);
char *CTRL_getRET(void);
int CTRL_getRETLEN(void);

