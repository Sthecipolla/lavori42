#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


void child_do(char **cmds)
{
	execvp(cmds[0], cmds);
	exit(2);
}

int last_cmd(char **cmds, int i)
{
	execvp(cmds[i], cmds);
	exit(2);
}

int    picoshell(char **cmds[])
{
	int l = 0;
	int id;
	int fdPipe[2];
	while(cmds[l + 1] != NULL)
	{
		pipe(fdPipe);
		id = fork();
		if (id == 0)
		{
			close(fdPipe[0]);
			dup2(fdPipe[1], 1);
			close(fdPipe[1]);
			child_do(cmds[l]);
		}
		else
		{
			close(fdPipe[1]);
			dup2(fdPipe[0], 0);
			close(fdPipe[0]);
		}
		l++;
	}
	id = fork();
	if (id == 0)
	{
		last_cmd(*cmds, l + 1);
	}
	while (wait(&id) > 0);
	return (0);
}
/* 
Examples: 
	./picoshell /bin/ls "|" /usr/bin/grep picoshell
	picoshell
	./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
	squblblb
*/

// Include for string manipulation
#include <string.h>

// Helper to split argv into pipeline commands
int split_pipeline(char **argv, char ***cmds) {
	int count = 0, i = 1, start = 1;
	while (argv[i]) {
		if (strcmp(argv[i], "|") == 0) {
			argv[i] = NULL;
			cmds[count++] = &argv[start];
			start = i + 1;
		}
		i++;
	}
	if (start < i)
		cmds[count++] = &argv[start];
	return count;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]);
		return 1;
	}
	char *cmds[32]; // supports up to 32 pipeline commands
	split_pipeline(argv, cmds);
	picoshell(cmds);
	return 0;
}
/* int main(int argc, char **argv)
{
	
} */