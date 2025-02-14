/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:31:46 by lhima             #+#    #+#             */
/*   Updated: 2025/02/12 21:31:46 by lhima            ###   ########.fr       */
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

char	*find_command(char *argv, char **envp);
int		find_space(const char *s, int c);
void	child(char	*argv, char	**envp, int fd[2], int *file);
void	parent(int fd[2]);

#endif
