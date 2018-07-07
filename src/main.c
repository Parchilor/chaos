#include <stdio.h>

char in[128] = "init i2c pn adc\n";

int main(int argc, char *argv[])
{
	char *p_in = in;
	int cnt = 0;
	const char* params[16];
	while(*p_in)
	{
	//	printf("%d ----> %s\n", cnt, *p_in);
		switch(*p_in)
		{
			case '\r':
			case '\n':
			case '\t':
			case ' ':
				p_in++;
				continue;
		}
		if(0 == *p_in)
			break;
		params[cnt] = p_in;
		cnt++;
		while(*p_in)
		{
			if ('\r' == *p_in ||'\n' == *p_in ||' '  == *p_in || '\t' == *p_in)
			{
				*p_in = '\0';
				p_in++;
				break;
			}
			p_in ++;
		}
	}

	int i;
	printf("count = %d\n", cnt);
	for(i = 0; i < cnt; i++)
	{
		printf("params[%d] = %s ", i, params[i]);
	}
	putchar('\n');
	putchar('\n');
	return 0;
}
