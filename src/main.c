#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
//#include <>

#include "cJSON.h"
#include "list.h"

typedef struct {
	char	*token;
	char	*admin;
	char	*password;
	int		year;
	int		mon;
	int		mday;
	int		hour;
	int		min;
	int		sec;
	struct list_head *list;
}TOKEN;

typedef struct {
	FILE *tk_fp;
	TOKEN token;
}LOG_CTRL;
void get_localtime(TOKEN *r)
{
	static char timestr[33];	
	memset(timestr, 0, sizeof(timestr));	
	time_t t;
	struct tm *nowtime;
	time(&t);
	nowtime = localtime(&t);
	r->year = nowtime->tm_year +1900;
	r->mon = nowtime->tm_mon +1;
	r->mday = nowtime->tm_mday;
	r->hour = nowtime->tm_hour;
	r->min = nowtime->tm_min;
	r->sec = nowtime->tm_sec;
	printf("%d/%d/%d %d:%d:%d\n", 
			nowtime->tm_year + 1900, 
			nowtime->tm_mon + 1, 
			nowtime->tm_mday, 
			nowtime->tm_hour, 
			nowtime->tm_min, 
			nowtime->tm_sec);
}

void list_list_init(TOKEN *r)
{
	memset(r, 0, sizeof(TOKEN) *1);
	r->list = malloc(sizeof(TOKEN) *1);
	INIT_LIST_HEAD(r->list);
}

void list_token_init(TOKEN *r, int len)
{
	r->token = malloc(sizeof(char) * len);
}

void list_admin_init(TOKEN *r, int len)
{
	r->admin = malloc(sizeof(char) * len);
}

void list_password_init(TOKEN *r, int len)
{
	r->password = malloc(sizeof(char) * len);
}

void list_node_init(TOKEN *r, int tklen, int alen, int pwlen)
{
	list_token_init(r, tklen);
	list_admin_init(r, alen);
	list_password_init(r, pwlen);
	get_localtime(r);
}

char *readline(FILE *file, int line, int *size)
{
	char c;
	int CR_cnt = 0;
	int cur_line_start = 0, cur_line_end = 0, slen;
	// To get a length for return string
	fseek(file, 0, SEEK_SET);
	for(CR_cnt = 0; CR_cnt < line;)
	{
		c = fgetc(file);
		if(c == '\n' || feof(file))
		{
			cur_line_start = cur_line_end;
			cur_line_end = ftell(file);
			CR_cnt++;
		}
	}

	slen = cur_line_end - cur_line_start;
	// Return length
	if(size != NULL)
	{
		*size = slen;
	}

	// Start to get data
	char *ret = malloc(sizeof(char) * (slen));
	fseek(file, cur_line_start, SEEK_SET);
	fgets(ret, slen, file);
	if(cur_line_start == cur_line_end)
	{
		free(ret);
		ret = NULL;
	}
	return ret;
}

void get_one_token(TOKEN *r)
{

	r->token = readline(r->tk_fp, 1, NULL);

}

int main(int argc, char *argv[])
{
	LOG_CTRL *tklist = malloc(sizeof(LOG_CTRL) *1);
	tklist->token.list = malloc(sizeof(struct list_head) *1);
	INIT_LIST_HEAD(tklist->token.list);
//	get_one_token(tklist);
	char *tmp;
	FILE *fp = fopen("files/token", "r");
	if(fp == NULL)
	{
		printf("Opened files fail!\n");
		exit(-1);
	}
	
	int line = atoi(argv[1]);
	int size = 0;
	tmp= readline(fp, line, &size);
	get_localtime(&tklist->token);
	printf("%s\t\n%d\n", tmp, size);
	return 0;
}
