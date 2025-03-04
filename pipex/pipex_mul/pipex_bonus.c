/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:30:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/28 11:23:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	free_matrix(char **matrix)
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
	char	*c;

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
		c = ft_strjoin(path[i], "/");
		command = ft_strjoin(c, argv);
		free(c);
		if (access(command, F_OK) == 0)
			return (free_matrix(path), command);
		free(command);
		i++;
	}
	return (free_matrix(path), NULL);
}

void	parent(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}
