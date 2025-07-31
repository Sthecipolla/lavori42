/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:30:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/26 15:19:09 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Max number of fd supported by the system
// Check this limit using the command "ulimit -n"
# define MAX_FD 1024

# include <unistd.h>	// read
# include <stdlib.h>	// malloc, free, size_t

// File get_next_line.c
char	*get_next_line(int fd);
char	*read_line(int fd, char **left_chars, char *buf);
char	*manage_left_chars(char **left_chars);
char	*set_line(char *tmp_line, char **left_chars);

// File get_next_line_utils.c
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif