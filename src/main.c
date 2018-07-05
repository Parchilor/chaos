#include "c_inc.h"

enum mode{
	VOLUME,
	ALBUM,
	FHR,
	MUSIC,
};

char *Get_Mode(enum mode str)
{
	char *ret =malloc(sizeof(char) * 8);
	switch(str)
	{
		case VOLUME:
			sprintf(ret, "VOLUME");
			break;
		case ALBUM:
			sprintf(ret, "ALBUM");
			break;
		case FHR:
			sprintf(ret, "FHR");
			break;
		case MUSIC:
			sprintf(ret, "MUSIC");
			break;
	}
	return ret;
}

int
main (int argc, char *argv[])
{
	printf ("Testing!\nMode: %s\n", Get_Mode(VOLUME));
	return 0;
}
