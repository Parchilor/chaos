#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <id3tag.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/utsname.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

/*
int
main (int argc, char *argv[])
{
	struct id3_file *mp3_id3 = id3_file_open("files/fish.mp3", ID3_FILE_MODE_READWRITE);
	if(mp3_id3 == NULL)
	{
		printf("open fail!\n");
		return -1;
	}
	struct id3_tag *tag = id3_file_tag(mp3_id3);
	printf("TAG offset: %ld\n", ftell(mp3_id3->iofile));
	id3_file_close(mp3_id3);
	return 0;
}
*/

#define	ID3V1	"TAG"
#define	ID3V2	"ID3"
#define	ID3V3	""

int main(int argc, char *argv[])
{
	int ret = 0;
	char tag[128] = { 0 }; 
	FILE *fp = fopen("files/fish.mp3", "r+b");
	if(fp == NULL)
	{
		printf("File Opened Fail!\n");
		return -1;
	}
	if((fread(tag, 128, 1, fp)) == 0)
	{
		printf("Read None!!!\n");
		return -2;
	}
	if(!strncmp(tag, ID3V1, 3))
	{
		printf("%s\n", ID3V1);
	}
	else if(!strncmp(tag, ID3V2, 3))
	{
		printf("%s\n", ID3V2);
	}
	else
	{
		printf("Invail!\n");
	}
	return 0;
}
