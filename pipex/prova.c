#include "pipex.h"

int	for_the_forking(pid_t *childpid)
{
	*childpid = fork();
	if (*childpid == -1)
	{
		perror("error fork\n");
		exit(1);
	}
	return (0);
}


void	argc_check_and_fd(int argc, int *file, char **argv)
{
	if (argc != 5)
	{
		perror("error argc\n");
		exit(1);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

void	child_do(int argc, char **argv, char **envp, int *fd)
{
	pid_t	childpid;
	int		i;

	i = -1;
	while (argc - 4 > ++i)
	{
		if (pipe(fd) == -1)
		{
			perror("error pipe\n");
			exit(1);
		}
		for_the_forking(&childpid);
		if (childpid == 0)
		{
			close(fd[0]);
			child(argv[2 + i], envp, fd);
		}
		else
			parent(fd);

		close(fd[0]);
	}
	wait(NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	int		fd[2];
	int		file[2];
	pid_t	childpid;
	int i;

	i = -1;
	argc_check_and_fd(argc, file, argv);
	pipe(fd);

	while(argc - 3 > ++i)
	{
		for_the_forking(&childpid);
		if (childpid == 0)
		{
			dup2(file[0], 0);
			close(file[0]);
			dup2(file[1], 1);
			close(file[1]);
			//child_do(argc, argv, envp, fd);
			execve(find_command(ft_substr(argv[argc - 2], 0, \
			find_space(argv[argc - 2], ' ')), envp), \
			ft_split(argv[argc - 2], ' '), envp);
		}
		else if(childpid == 0 && i != 0)
		{
			close(file[0]);
			close(file[1]);
			dup2(fd[0], 0);
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execve(find_command(ft_substr(argv[argc - 2], 0, \
			find_space(argv[argc - 2], ' ')), envp), \
			ft_split(argv[argc - 2], ' '), envp);
		}
		else
		{
			//close(file[1]);
			dup2(fd[0], 0);
		}


	}
	wait(NULL);
	close(file[0]);
	close(file[1]);
	return (0);
}



[






]

/* 	dup2(file[1], 1);
	for_the_forking(&childpid);
	if (childpid == 0)
	{
		close(file[0]);
		child_do(argc, argv, envp, fd, file);
		close(file[1]);
		execve(find_command(ft_substr(argv[argc - 2], 0, \
		find_space(argv[argc - 2], ' ')), envp), \
		ft_split(argv[argc - 2], ' '), envp);
	}
	else
	{
		close(file[1]);
		dup2(file[0], 0);
	}
	waitpid(childpid, NULL, 0);
	close(file[0]); */
