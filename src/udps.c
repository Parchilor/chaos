#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define	MAXLINE	4096
#define	MAXNUM	10
struct udp_data	{
	int dest_sock;
	struct sockaddr_in *local_addr;
	struct sockaddr_in *dest_addr;
};

struct sockaddr_in *sockaddr_in_init(char *addr, int port)
{
	struct sockaddr_in *dest = malloc(sizeof(struct sockaddr_in));
	if (dest == NULL)
	{
		printf("malloc error: %s (errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	memset(dest, 0, sizeof(struct sockaddr_in));
	dest->sin_family = AF_INET;
	if (strcmp(addr, "INADDR_ANY") == 0)
	{
		dest->sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		dest->sin_addr.s_addr = inet_addr(addr);
	}
	dest->sin_port = htons(port);
	return dest;
}

int main (int argc, char *argv[])
{
	int conn_sock, dest_sock;
	struct udp_data data;
	char buff[MAXLINE];
	int ret, quit = 1;
	unsigned int sin_size = sizeof(struct sockaddr);
	
	if ((conn_sock = socket (AF_INET, SOCK_DGRAM, 0)) == -1)	{
		printf ("Create sockt error: %s (errno: %d)\n", strerror (errno), errno);
		exit (0);
	}
	data.local_addr = sockaddr_in_init("INADDR_ANY", 6667);
	if (bind(conn_sock, (struct sockaddr *)data.local_addr, sizeof(struct sockaddr_in)) == -1) {
		printf ("Bind socket error: %s (errno: %d)\n", strerror (errno), errno);
		exit (0);
	}

	printf("Wainting for client MSG!\n");
	while (quit)	{
		printf("MSG: ");
		ret = recvfrom (conn_sock, buff, MAXLINE-1, 0, (struct sockaddr_in *)data.dest_addr, &sin_size);
		if (!strncmp (buff, "quit", 1) | !strncmp (buff, "exut", 1))	{
			quit = 0;
		}
		buff[ret] = '\0';
		printf ("%s\n", buff);
	}
	return 0;
}
