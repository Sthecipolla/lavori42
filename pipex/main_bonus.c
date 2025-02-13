/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:17 by lhima             #+#    #+#             */
/*   Updated: 2025/02/13 15:35:07 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	child_do(int argc, char **argv, char **envp, int fd[2])
{
	pid_t	childpid;
	int		i;

	i = -1;
	close(fd[0]);
	close(fd[1]);
	
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
			close(fd[1]);
			child(argv[2 + i], envp, fd);
		}
		else
			parent(fd);
		wait(NULL);
	}
}

void	argc_check_and_fd(int argc, int *file, char **argv)
{
	if (argc < 5)
	{
		perror("error argc\n");
		exit(1);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}
void	here_doc(char **argv, int *fd,int argc)
{
	char	*line;
	int		i;

	if(argc != 6)
		return ;
	i = 0;
	fd[0] = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	line = get_next_line(0);
	while (ft_strncmp(line, argv[2],ft_strlen(argv[2])) != 0)
	{
		write(fd[0], line, ft_strlen(line));
		if(line != NULL)
			free(line);
		line = get_next_line(0);
		if(line == NULL)
			break;
	}
	if(line != NULL)
		free(line);
	close(fd[0]);
}
int	main(int argc, char **argv, char *envp[])
{
	int		fd[2];
	int		file[2];
	pid_t	childpid;

	argc_check_and_fd(argc, file, argv);
	if(ft_strncmp(argv[1], "here_doc",ft_strlen("here_doc")) == 0)
		here_doc(argv, fd, argc);
	dup2(file[0], 0);
	for_the_forking(&childpid);
	if (childpid == 0)
	{
		child_do(argc, argv, envp, fd);
		dup2(file[1], 1);
		execve(find_command(ft_substr(argv[argc - 2], 0, \
		find_space(argv[argc - 2], ' ')), envp), \
		ft_split(argv[argc - 2], ' '), envp);
	}
	else
	{
		waitpid(childpid, NULL, 0);
		close(file[0]);
		close(file[1]);
		if(ft_strncmp(argv[1], "here_doc",ft_strlen("here_doc")) == 0 && argc == 6)
			unlink("here_doc");
	}
	return (0);
}
