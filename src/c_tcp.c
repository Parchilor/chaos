#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
	int	sock_fd, ret;
	char	recvbuf[4096], sendbuf[4096];
	struct sockaddr_in	svraddr;

	if(argc != 2){
		printf("usage: ./c_tcp <ipaddress>\n");
		exit(0);
	}

	if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)		{
		printf("Create socket error: %s (errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	memset(&svraddr, 0, sizeof(svraddr));
	svraddr.sin_family = AF_INET;
	svraddr.sin_port = htons(6666);
	svraddr.sin_addr.s_addr = inet_addr (argv[1]);
#if 0
	if(inet_pton(AF_INET, argv[1], &svraddr.sin_addr) <= 0)	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}
#endif

		if(connect(sock_fd, (struct sockaddr*)&svraddr, sizeof(svraddr)) < 0)	{
			printf("Connect error: %s (errno: %d)\n", strerror(errno), errno);
			exit(0);
		}
		printf(":---->> Connected to Server\n");
		printf(":---->> Server IP: %s\n", argv[1]);
	int quit = 1;
	while(quit)	{
		printf("Enter MSG: ");
		fgets(sendbuf, 4096, stdin);
		if(send(sock_fd, sendbuf, strlen(sendbuf), 0) < 0)	{
			printf("Send msg error: %s (errno: %d)\n", strerror(errno), errno);
			exit(0);
		}
		if (!strncmp (sendbuf, "quit", 1) | !strncmp (sendbuf, "exit", 1))	{
			quit = 0;
		}
	}
	close(sock_fd);
	return 0;
}
