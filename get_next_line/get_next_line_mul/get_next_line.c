/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:12 by lhima             #+#    #+#             */
/*   Updated: 2024/12/21 09:26:17 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		check(char *str);
static size_t	ft_readstr(int fd, char **str, char **plus, size_t y);
static char		*ft_retstr(char *str, size_t limit);
static size_t	ft_count_plus(char *str, char **plus);

static size_t	ft_readstr(int fd, char **str, char **plus, size_t y)
{
	char	*buffer;
	char	*app;
	int		x;

	app = *plus;
	if (*plus != NULL && *plus[0] != '\0')
	{
		while ((*plus)[y] != '\n' && (*plus)[y] != '\0')
			y++;
		if ((*plus)[y] != '\0')
			y++;
		*plus = ft_strjoin(ft_calloc(1, 1), &(*plus)[y], app);
	}
	while (check(*str) == 0)
	{
		buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == 0)
			return (free(buffer), free(*plus), *plus = NULL, ft_strlen(*str));
		else if (x < 0)
			return (free(buffer), free(*plus), *plus = NULL, 0);
		*str = ft_strjoin(*str, buffer, ft_calloc(1, 1));
		free(buffer);
	}
	return (ft_count_plus(*str, &(*plus)) + 1);
}

int	check(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		if (str[x++] == '\n')
			return (1);
	return (0);
}

size_t	ft_count_plus(char *str, char **plus)
{
	size_t	x;
	char	*app;

	app = *plus;
	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x + 1] != '\0' && ft_strncmp((*plus), str) != 0)
	{
		*plus = ft_strjoin(ft_calloc(1, 1), &str[x + 1], ft_calloc(1, 1));
		free(app);
	}
	return (x);
}

static char	*ft_retstr(char *str, size_t limit)
{
	char	*c;
	size_t	x;

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

char	*get_next_line(int fd)
{
	char		*str;
	static char	*plus;
	size_t		lim;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (plus == NULL)
		plus = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	str = ft_calloc(1, 1);
	str = ft_strjoin(str, plus, ft_calloc(1, 1));
	lim = ft_readstr(fd, &str, &plus, 0);
	if (lim == 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_retstr(str, lim);
	return (str);
}
/*
int main()
{
	int fd;
	char *f = "dasd";
	int x = 1;
	// char c[BUFFER_SIZE];

	fd = open("prova.txt", O_RDONLY, 777);
	while (f != NULL)
	{
		f = get_next_line(fd);
		if (f != NULL)
			printf("linea %d%s%s", x++, ": ", f);
		if (f != NULL)
			free(f);
	}
	printf("\nfine.\n");
	close(fd);
	printf("%c", '\n');
	return (0);
}*/
