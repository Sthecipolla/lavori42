/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:25:56 by lhima             #+#    #+#             */
/*   Updated: 2025/02/25 14:36:18 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(char **argv, char **envp, t_pipex p)
{
	char *command;
	char *str;

	close(p.fd[0]);
	dup2(p.fd[1], 1);
	close(p.file[1]);
	close(p.fd[1]);
	str = ft_substr(argv[2], 0, find_space(argv[2], ' '));
	command = find_command(str, envp);
	free(str);
	if(command == NULL)
		exit(0);
	execve(command,	ft_split(argv[2], ' '), envp);
}

void	last_command(char **argv, char **envp, t_pipex p, int i)
{
	char *command;
	char *str;

	dup2(p.file[1], 1);
	close(p.file[1]);
	str = ft_substr(argv[2 + i], 0, find_space(argv[2 + i], ' '));
	command = find_command(str, envp);
	free(str);
	if(command == NULL)
		exit(0);
	execve(command, ft_split(argv[2 + i], ' '), envp);
}
