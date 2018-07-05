#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void 
*loop_test(void *data)
{
	int i = 0;
	do {
		sleep(1);
		putchar('.');
		fflush(stdout);
		i++;
	} while (i < 10);
	putchar('\n');
	return NULL;
}

pthread_t pid;

void
Signal_Init (int sig, struct sigaction *act, struct sigaction *oact, void (*handler)(int))
{
	act->sa_handler = handler;
	act->sa_flags = 0;
	sigemptyset (&act->sa_mask);
	sigaction (sig, act, oact);
}

void
pr_mask(const char *str)
{
	sigset_t newmask, oldmask, pendmask;
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	loop_test(NULL);
//	sigpending(&pendmask);
//	if(sigismember(&pendmask, SIGQUIT))
//		printf("\nSIGQUIT Pending\n");
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	printf("SIGQUIT unblocked\n");
	loop_test(NULL);
}

static void
sig_handler(int sig)
{
//	signal(SIGQUIT, SIG_DFL);
	printf("interrupt!");
	fflush(stdout);
}

int
main (int argc, char *argv[])
{
	pthread_t sig_pid;
	int i;
	struct sigaction act, oact;
	Signal_Init (SIGINT, &act, &oact, sig_handler);
	pr_mask(NULL);
	return 0;
}
