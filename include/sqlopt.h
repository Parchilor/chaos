#ifndef __SQL_OPT_
#define __SQL_OPT_

#include "sqlite3.h"

#define FILE_NAME_SIZE 128
#define CMD_SIZE 1024
#define ERR_SIZE 1024

typedef struct {
	char filename[FILE_NAME_SIZE];
	sqlite3 *db;
	int fd;

	int (*_callback)(void*, int, char **, char **);
	void *data;
	char **errmsg;

	char sql[CMD_SIZE];
	int ret;
} sqlopt;

#define SQL_FILE_INIT(fname) .filename = fname
#define SQL_EXEC_INIT(callback, dat) \
	._callback = callback, .data = dat
#define SQL_EXEC_COMMAND_INIT(cmd) \
	.sql = cmd
#define SQL_EXEC_COMMAND(st_opt, cmd) \
	sprintf(st_opt.sql, cmd)

#define SQL_Open(st_opt) st_opt.fd = sqlite3_open(st_opt.filename, &st_opt.db)
#define SQL_Exec(st_opt) st_opt.ret = sqlite3_exec(st_opt.db, st_opt.sql, st_opt._callback, st_opt.data, st_opt.errmsg)
#define SQL_Close(st_opt) sqlite3_close(st_opt.db)

#endif
