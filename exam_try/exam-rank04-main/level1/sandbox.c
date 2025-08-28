#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int ret_false()
{
   return 0; 
}

int ret_true()
{
   return 1; 
}


void timeout()
{
   while(1); 
}

int signal_handler(int num)
{
	exit(SIGALRM);
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int id;
	struct sigaction sa;
	int exit_status;


	id = fork();
	if (id == 0)
	{
		sa.sa_handler = signal_handler;
		sa.sa_flags = 0;
		sigaction(SIGALRM, &sa, NULL);
		alarm(timeout);
		f();
		exit(0);
	}
	waitpid(-1, &exit_status, 0);
	exit_status = WEXITSTATUS(exit_status);
	if (verbose == false)
		return (exit_status);
	if(exit_status == 0)
	{
		printf("Nice function!\n");
		return (1);
	}
	else if (exit_status == SIGALRM)
		printf("Bad function: timed out after %d seconds\n", timeout);
	else if(WIFSIGNALED(exit_status))
		printf("Bad function: %s\n", strsignal(WTERMSIG(exit_status)));
	else
	{
		printf("Bad function: exited with code %d\n", exit_status);
		return (-1);
	}
	return(0);

}

int main()
{
	printf("%d:\n ", sandbox(timeout, 5, true));
}