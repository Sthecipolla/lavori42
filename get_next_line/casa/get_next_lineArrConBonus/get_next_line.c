/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:04:12 by lhima             #+#    #+#             */
/*   Updated: 2024/12/27 12:04:12 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
#include "get_next_line.h"

static int		check(char *str);
static int		ft_readf(int fd, char **str, char *plus, int y);
static char		*ft_retstr(char *str, size_t limit);
static int		ft_len_and_fill(char *plus, char *str);

int ft_readf(int fd, char **str, char *plus, int y)
{
	char	*buffer;
	int		x;

	if (plus[0] != '\0')
	{
		while (plus[y] != '\n' && plus[y] != '\0')
			y++;
		if (plus[y] != '\0')
			y++;
		cut(plus, &plus[y], BUFFER_SIZE + 1);
	}
	while (check(*str) == 0)
	{
		buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == 0)
			return (free(buffer), ft_len_and_fill(plus, *str));
		else if (x < 0)
			return (free(buffer), 0);
		*str = ft_strjoin(*str, buffer);
		free(buffer);
	}
	return (ft_len_and_fill(plus, *str) + 1);
}
int ft_len_and_fill(char *plus, char *str)
{
	int x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x] != '\0' && plus[0] == '\0')
		cut(plus, &str[x + 1], BUFFER_SIZE);
	return (x);
}

int check(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		if (str[x++] == '\n')
			return (1);
	return (0);
}
static char *ft_retstr(char *str, size_t limit)
{
	char *c;
	size_t x;

	c = 0;
	x = 0;
	c = ft_calloc((size_t)limit + 1, 1);
	while (str[x] != '\n' && str[x] != '\0')
	{
		c[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		c[x++] = '\n';
	free(str);
	return (c);
}

char *get_next_line(int fd)
{
	char *str;
	static char plus[BUFFER_SIZE + 1];
	int len;

	if (fd < 0 || BUFFER_SIZE < 1)
			return (NULL);
	{
		str = ft_calloc(1, 1);
		str = ft_strjoin(str, plus);
		len = ft_readf(fd, &str, plus, 0);
		if (len == 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_retstr(str, len);
	}
	return (str);
} */

/* int main()
{
	int fd[3];
	char *f = "not null";
	int x = 1;
	fd[0] = open("prova.txt", O_RDONLY, 777);
	fd[1] = open("prova.txt", O_RDONLY, 777);
	fd[2] = open("prova.txt", O_RDONLY, 777);
	
	if (f == NULL)
	{
		f = get_next_line(fd[0]);
		if (f != NULL)
			printf("linea %d%s%s", x++, ": ", f);
		if (f != NULL)
			free(f);
	}
	else
	{
		while (f != NULL)
		{
			f = get_next_line(fd[0]);
			if (f != NULL)
				printf("linea lunga %ld numero %d%s%s", ft_strlen(f), x, ": ", f);
			if (f != NULL)
			{

				free(f);
			}
			f = get_next_line(fd[1]);
			if (f != NULL)
				printf("linea lunga %ld numero %d%s%s", ft_strlen(f), x, ": ", f);
			if (f != NULL)
			{

				free(f);
			}
			f = get_next_line(fd[2]);
			if (f != NULL)
				printf("linea lunga %ld numero %d%s%s", ft_strlen(f), x, ": ", f);
			if (f != NULL)
			{

				free(f);
			}
			x++;
		}
		printf("\nfine.\n");
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
	}
	return (0);
} */