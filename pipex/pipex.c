/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:30:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/19 15:21:56 by lhima            ###   ########.fr       */
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

void free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
		{
			free_matrix(path);
			return (command);
		}
		free(command);
		i++;
	}
	free_matrix(path);
	return (NULL);
}

void	parent(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}
