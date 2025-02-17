/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:17 by lhima             #+#    #+#             */
/*   Updated: 2025/02/15 14:52:01 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	child_do(int argc, char **argv, char **envp, int *fd)
{
	pid_t	childpid;
	int		i;

	i = -1;
	dup2(fd[1], 1);
	close(fd[1]);
	child(argv[2 + i], envp, fd);
	while (argc - 4 > ++i)
	{
		for_the_forking(&childpid);
		if (childpid == 0)
		{
			dup2(fd[1], 1);
			close(fd[1]);
			child(argv[2 + i], envp, fd);
		}
		dup2(fd[0], 0);
		close(fd[0]);
	}
	parent(fd);
	wait(NULL);
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

int	main(int argc, char **argv, char *envp[])
{
	int		fd[2];
	int		file[2];
	pid_t	childpid;

	argc_check_and_fd(argc, file, argv);
	for_the_forking(&childpid);
	if (pipe(fd) == -1)
	{
		perror("error pipe\n");
		exit(1);
	}
	if (childpid == 0)
	{
		dup2(file[0], 0);
		close(file[0]);
		dup2(file[1], 1);
		close(file[1]);
		child_do(argc, argv, envp, fd);
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
	close(file[0]);
	return (0);
}
