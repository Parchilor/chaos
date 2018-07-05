#include "c_inc.h"
#include <time.h>
#include <getopt.h>
#include <unistd.h>

enum rdmode {
	RSM_Capital = 1,
	RSM_Letter,
	RSM_Cap_Let,
	RSM_Number,
	RSM_Cap_Num,
	RSM_Let_Num,
	RSM_ALL,
};

char BC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char SC[] = "abcdefghijklmnopqrstuvwxyz";
char NO[] = "0123456789";

struct option long_opts[] = {
	{"len", required_argument, NULL,'l'},
	{"mode", required_argument, NULL,'m'},
	{0,0,0,0},
};

char 
*CreateToken(int len, enum rdmode mode);

int
main (int argc, char *argv[])
{
	int c, len, mode;
	while((c = getopt_long(argc, argv, "l:m:", long_opts, NULL)) != -1){
		switch(c){
			case 'l':
				len = atoi(optarg);
				break;
			case 'm':
				mode = atoi(optarg);
				break;
		}
	}
	char *token = CreateToken(len, mode);
	printf("%s\n", token);
	return 0;
}

char 
*CreateToken(int len, enum rdmode mode)
{
	int maxLen = 0, i, index;
	char select[62];
	char *str = malloc(sizeof(char) * len);


	srand((unsigned)time(NULL));
	switch(mode){
		case RSM_Capital:
			sprintf(select, "%s", BC);
			maxLen = 26;
			break;

		case RSM_Letter:
			sprintf(select, "%s", SC);
			maxLen = 26;
			break;

		case RSM_Cap_Let:
			maxLen = 52;
			sprintf(select, "%s%s", SC, BC);
			break;

		case RSM_Number:
			sprintf(select, "%s", NO);
			maxLen = 10;
			break;

		case RSM_Cap_Num:
			sprintf(select, "%s%s", NO, BC);
			maxLen = 36;
			break;

		case RSM_Let_Num:
			sprintf(select, "%s%s", NO, SC);
			maxLen = 36;
			break;

		case RSM_ALL:
			sprintf(select, "%s%s%s", NO, SC, BC);
			maxLen = 62;
			break;
		default:
			sprintf(select, "%s", BC);
			maxLen = 26;
	}
	for(i = 0; i < len; i++){
		index = rand()%(maxLen);
		str[i] = select[index];
	}
	return str;
}
