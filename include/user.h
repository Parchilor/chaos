#pragma once
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
/*
int 
err_quit (char *fmt, ## __VA_ARGS__)
{
	printf (fmt"%s (%d)", ## __VA_ARGS__, strerror(errno), errno);
	return errno;
}
*/
#define err_quit(fmt, ...)	do	{ \
								printf(fmt ": %s (%d)\n", ## __VA_ARGS__, strerror (errno), errno); \
								exit (errno); \
							}while(0)

#define err_ret(fmt, ...)	do	{ \
								printf(fmt ": %s (%d)\n", ## __VA_ARGS__, strerror (errno), errno); \
							}while(0)
