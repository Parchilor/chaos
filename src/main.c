#include "c_inc.h"

int 
main (int argc, char *argv[])
{
	struct utsname name;
	uname (&name);
	printf("    SYSNAME:	%s\n"
		   "   NODENAME:	%s\n"
		   "    RELEASE:	%s\n"
		   "    VERSION:	%s\n"
		   "    MACHINE:	%s\n", 
			name.sysname,
			name.nodename,
			name.release,
			name.version,
			name.machine);
	return 0;
}
