/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:30:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/17 16:54:03 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_command(char *argv, char **envp)
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

void	child(char	*argv, char **envp, int fd[2])
{
	char	*command;

	if(fd[1] == -1)
	{
		exit(0);
	}
	command = find_command(ft_substr(argv, 0, find_space(argv, ' ')), envp);
	if (execve(command, ft_split(argv, ' '), envp) == -1)
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
