#include "user.h"

#define	USR_MASK(mode)	((mode & 0x7) >> 0)
#define	GRP_MASK(mode)	((mode & (0x7 << 3)) >> 3)
#define	OTH_MASK(mode)	((mode & (0x7 << 6)) >> 6)
#define	RWX	0x7
#define RW_	0x6
#define	R_X	0x5
#define	R__	0x4
#define	_WX	0x3
#define	_W_	0x2
#define	__X	0x1
#define ___	0x0

char *S_GetMode(struct stat *stp);
char *S_GetLink(struct stat *stp);
char *S_GetID (struct stat *stp);
char *S_GetSize (struct stat *stp);
char *S_GetTime (struct stat *stp);

int
main (int argc, char *argv[])
{
// <type><mode> <dir num> <owner> <group> <size> <build date> <name>
	DIR				*dp;
	struct dirent	*dirp;
	struct stat		stp;
	char			ret[512];

	if ((dp = opendir (argv[1])) == NULL)
		err_quit ("Can not open %s", argv[1]);
	while ((dirp = readdir (dp)) != NULL)	{
		if (lstat (dirp->d_name , &stp) < 0)	{
			err_ret ("Can not lstat %s", dirp->d_name);
			continue;
		}
		sprintf (ret,"%s %s %s %s %s", S_GetMode (&stp), S_GetLink (&stp), S_GetID (&stp), S_GetSize (&stp), S_GetTime (&stp));
//		ret[strlen(ret)-1] = ' ';
		sprintf (&ret[strlen(ret)-1]," %s\n", dirp->d_name);
		printf("%s", ret);
//		fputs (ret, stdout);
	}
	closedir (dp);
	return 0;
}


char 
*S_GetMode(struct stat *stp)
{
	char *mode = malloc (sizeof(char) * 512);
	unsigned short ret;
	// type
	ret = stp->st_mode & S_IFMT;
	switch (ret)	{
		case S_IFREG:
			mode[0] = '-';
			break;
		case S_IFDIR:
			mode[0] = 'd';
			break;
		case S_IFCHR:
			mode[0] = 'c';
			break;
		case S_IFBLK:
			mode[0] = 'b';
			break;
		case S_IFIFO:
			mode[0] = 'f';
			break;
		case S_IFLNK:
			mode[0] = 'l';
			break;
		case S_IFSOCK:
			mode[0] = 's';
			break;
	}
	// attributes
	char i;
	memset (&mode[1], '-', 9);
	
	for (i = 0; i < 7; i += 3)	{
		if (i == 6)
			ret = USR_MASK (stp->st_mode);
		else if (i == 3)
			ret = GRP_MASK (stp->st_mode);
		else if (i == 0)
			ret = OTH_MASK (stp->st_mode);
		if ((ret >> 2) & 0x1)
			mode[1+i] = 'r';
		if ((ret >> 1) & 0x1)
			mode[2+i] = 'w';
		if ((ret >> 0) & 0x1)
			mode[3+i] = 'x';
	}
	return mode;
}

char 
*S_GetLink(struct stat *stp)
{
	char *link = malloc (sizeof(char) * 32);
	sprintf(link, "%4d", (int)stp->st_nlink);
	return link;
}

char 
*S_GetID (struct stat *stp)
{
	char *id = malloc (sizeof(char) * 126);
	sprintf (id, "%-8s %-8s", getpwuid (stp->st_uid)->pw_name, getgrgid(stp->st_gid)->gr_name);
	return id;
}

char 
*S_GetSize (struct stat *stp)
{
	char *size = malloc (sizeof(char) * 126);
	sprintf (size, "%8ld", stp->st_size);
	return size;
}

char 
*S_GetTime (struct stat *stp)
{
	char *time = malloc (sizeof(char) * 126);
	sprintf(time, "%.13s",4+ctime (&stp->st_mtime));
	return time;
}
