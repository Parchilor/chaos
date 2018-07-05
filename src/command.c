#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*
char **column = NULL;

void fill_command(char *cmd, char *col)
{
	column = malloc(sizeof(char *));
	column[0] = malloc(strlen(col) + 1);
	sprintf(column[0], "%s", col);
}

int main(void)
{
	char cmd[1024];
	char *arg = "Type";
	fill_command(cmd, arg);
	printf("%s\n", column[0]);

	return 0;
}
*/
void Set_Column(int cnt, ...)
{
	int i;
	char *tmp;
	va_list ap;
	va_start(ap, NULL);

	for(i = 0; i < cnt; i++)
	{
		tmp = va_arg(ap, char *);
		printf("%s ", tmp);
		fflush(stdout);
	}
}

void Set_Column_Type(int cnt, ...)
{
	int i;
	char *tmp;
	va_list ap;
	va_start(ap, NULL);

	for(i = 0; i < cnt; i++)
	{
		tmp = va_arg(ap, char *);
		printf("%s ", tmp);
		fflush(stdout);
	}
}

int main(void)
{
	Set_Column(4, "Type", "Company", "Version", "Price");
	putchar('\n');
	Set_Column_Type(4, "text", "text", "text", "integer");
	putchar('\n');
	return 0;
}
