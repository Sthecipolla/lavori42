/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:31:46 by lhima             #+#    #+#             */
/*   Updated: 2025/02/28 11:24:01 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include "./libft/libft.h"
# include "printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	int		file[2];
	int		status;
}	t_pipex;

char	*find_command(char *argv, char **envp);
int		find_space(const char *s, int c);
void	parent(int fd[2]);
void	ft_error(char *str);
void	first_command(char **argv, char **envp, t_pipex p);;
void	last_command(char **argv, char **envp, t_pipex p, int i);

#endif
