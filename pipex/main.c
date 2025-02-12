/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:17 by lhima             #+#    #+#             */
/*   Updated: 2025/02/12 17:22:37 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
char	*find_command(char *argv,char **envp)
{
	int		i;
	char	**path;
	char	*command;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_split(envp[i] + 5, ':');
		i++;
	}
	i = 0;
	while (path[i])
	{
		command = ft_strjoin(ft_strjoin(path[i], "/"), argv);
		if (access(command, F_OK) == 0)
			return (command);
		i++;
	}
	return (NULL);
}

int	find_space(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (i);
		i ++ ;
	}
	if (c == s[i])
		return (i);
	return (ft_strlen(s));
}

void	child(char	*argv,char	**envp, int fd[2])
{
	char	*command;

	dup2(fd[1], 1);
	command = find_command(ft_substr(argv, 0, find_space(argv, ' ')), envp);
	if(execve(command, ft_split(argv, ' '), envp) == -1)
	{
		perror("error execve\n");
		exit(1);
	}
}

void	parent(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], 0);
}

int main(int argc, char **argv, char *envp[])
{
	int		fd[2];
	int 	file[2];
	pid_t	childpid;
	pid_t	childpid2;
	int		i = 0;

	if(argc < 5)
	{
		ft_printf("error\n");
		exit(1);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(file[0], 0);
	if ((childpid2 = fork()) == -1)
	{
		perror("error fork\n");
		exit(1);
	}
	if (childpid2 == 0)
	{
		while(argc - 4 > i)
		{
			if(pipe(fd) == -1)
			{
				perror("error pipe\n");
				exit(1);
			}
			if((childpid = fork()) == -1)
			{
				perror("error fork\n");
				exit(1);
			}
			if(childpid == 0)
			{
				close(fd[0]);
				child(argv[2 + i], envp, fd);
			}
			else
				parent(fd);
			wait(NULL);
			i++;
		}
		dup2(file[1], 1);
		execve(find_command(ft_substr(argv[argc - 2], 0, find_space(argv[argc - 2], ' ')), envp), ft_split(argv[argc - 2], ' '), envp);
	}
	else
	{
		waitpid(childpid2, NULL, 0);
		close(file[0]);
		close(file[1]);
	}
	return (0);
}
