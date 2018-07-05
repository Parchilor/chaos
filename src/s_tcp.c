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
 
struct pthr_data
{
	int	dest_sock;
	struct sockaddr_in *dest_addr;
	struct sockaddr_in *local_addr;
};

void recieve_pthread(void *data)
{
	struct pthr_data *ptr = (struct pthr_data *)data;
	int ret, quit = 1;
	char buff[MAXLINE];
	while (quit) {
		ret = recv(ptr->dest_sock, buff, MAXLINE, 0);
		buff[ret] = '\0';
		if (!strncmp(buff, "quit", 1) | !strncmp(buff, "exit", 1)) {
			quit = 0;
		}
		printf("MSG: %s\n", buff);
	}
	close(ptr->dest_sock);
}

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
}

int main (int argc, char *argv[])
{
	pthread_t recv_id;
	
	int listen_sock, conn_sock;
	struct sockaddr_in server_addr, client_addr;
	char buff[MAXLINE];
	int ret, sin_size;
	struct pthr_data args;

	if ((listen_sock = socket (AF_INET, SOCK_STREAM, 0)) == -1)	{
		printf ("Create sockt error: %s (errno: %d)\n", strerror (errno), errno);
		exit (0);
	}
#if 1
	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr =  inet_addr("192.168.1.144");// htonl(INADDR_ANY); 
	server_addr.sin_port = htons (6666);
#else	server_addr = sockaddr_in_init("INADDR_ANY", 6666);#endif

	if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
		printf ("Bind socket error: %s (errno: %d)\n", strerror (errno), errno);
		exit (0);
	}

	if (listen (listen_sock, MAXNUM) == -1)	{
		printf ("Listen socket error: %s (errno: %d)\n", strerror (errno), errno);
		exit (0);
	}

	printf (":--- >> Listen Complete\n");

	memset(&client_addr, 0, sizeof(client_addr));
	if ((conn_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &sin_size)) == -1)
	{
		printf("Accept socket error: %s (errno: %d)\n", strerror(errno), errno);
		//			continue;
	}
	else
	{
		printf(":--- >> Client Connected!\n"
			":--- >> IP: %s\n"
			":--- >> Port: %d\n",
			inet_ntoa(client_addr.sin_addr),
			ntohs(client_addr.sin_port));
		args.dest_sock = conn_sock;
//		memcpy(&args.dest_addr, &client_addr, sizeof(struct sockaddr_in));
		args.dest_addr = &client_addr;
		pthread_create(&recv_id, NULL, (void *)recieve_pthread, &args);
	}
	pthread_join(recv_id, NULL);
	
	close (listen_sock);
	return 0;
}