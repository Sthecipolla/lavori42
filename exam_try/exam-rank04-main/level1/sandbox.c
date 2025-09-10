#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int allarm_sig = 0;

void signal_handler(int num)
{
	(void) num;
	allarm_sig = 1;
}

void kill_allarm(int num)
{
	kill(-1, num);
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int id;
	struct sigaction sa;
	int exit_status;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
	alarm(timeout);
	id = fork();
	if (id == 0)
	{
		sa.sa_handler = kill_allarm;
		sa.sa_flags = 0;
		sigaction(SIGALRM, &sa, NULL);
		f();
		exit(0);
	}
	waitpid(-1, &exit_status, 0);
	if (allarm_sig == 1)
	{
		if (verbose == true)
			printf("Bad function: timed out after %d seconds\n", timeout);
		allarm_sig = 0;
	}
	else if(WIFSIGNALED(exit_status))
	{
		if (verbose == true)
			printf("Bad function: %s\n", strsignal(WTERMSIG(exit_status)));
	}
	else if(WEXITSTATUS(exit_status) == 0)
	{
		if (verbose == true)
			printf("Nice function!\n");
		return (1);
	}
	else
	{
		if (verbose == true)
			printf("Bad function: exited with code %d\n", WEXITSTATUS(exit_status));
	}
	return(0);
}

void nice_function(void) {
	// exits normally
}

void bad_function(void) {
	// causes segmentation fault
	int *p = NULL;
	*p = 42;
}

void timeout_function(void) {
	while (1) {}
}

void nonzero_exit_function(void) {
	exit(42);
}

int main()
{
	printf("Testing nice_function (should be nice):\n");
	sandbox(nice_function, 2, true);

	printf("\nTesting bad_function (should be bad - segfault):\n");
	sandbox(bad_function, 2, true);

	printf("\nTesting timeout_function (should be bad - timeout):\n");
	sandbox(timeout_function, 1, true);

	printf("\nTesting nonzero_exit_function (should be bad - exit code):\n");
	sandbox(nonzero_exit_function, 2, true);

	return 0;
}