/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:25:56 by lhima             #+#    #+#             */
/*   Updated: 2025/02/19 14:44:15 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_command(char **argv, char **envp, t_pipex p)
{
	close(p.fd[0]);
	dup2(p.fd[1], 1);
	close(p.file[1]);
	close(p.fd[1]);
	execve(find_command(ft_substr(argv[2], 0, \
	find_space(argv[2], ' ')), envp), \
	ft_split(argv[2], ' '), envp);
}

void	command(char **argv, char **envp, t_pipex p, int i)
{
	close(p.file[1]);
	close(p.fd[0]);
	dup2(p.fd[1], 1);
	close(p.fd[1]);
	execve(find_command(ft_substr(argv[2 + i], 0, \
	find_space(argv[2 + i], ' ')), envp), \
	ft_split(argv[2 + i], ' '), envp);
}

void	last_command(char **argv, char **envp, t_pipex p, int i)
{
	dup2(p.file[1], 1);
	close(p.file[1]);
	execve(find_command(ft_substr(argv[2 + i], 0, \
	find_space(argv[2 + i], ' ')), envp), \
	ft_split(argv[2 + i], ' '), envp);
}
