/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:05:02 by lhima             #+#    #+#             */
/*   Updated: 2025/01/13 10:58:53 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(const char *c)
{
	size_t	x;

	x = 0;
	while (c && c[x] != 0)
		x++;
	return (x);
}

void	*ft_calloc_get(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	i = 0;
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)s)[i++] = 0;
	}
	return ((void *)s);
}

static size_t	ft_strtcpy_get(const char *s, char *cpy, size_t j)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		cpy[j] = s[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	i = ft_strlen_get(s1);
	i = i + (ft_strlen_get(s2));
	j = 0;
	str = (char *)ft_calloc_get((i + 1), 1);
	if (str == NULL)
		return (NULL);
	j = ft_strtcpy_get(s1, str, j);
	j = ft_strtcpy_get(s2, str, j);
	free(s1);
	str[i] = '\0';
	return (str);
}

void	cut(char *s, char *start, int len)
{
	int	x;

	x = -1;
	while (start[++x] != '\0')
		s[x] = start[x];
	while (x < len)
		s[x++] = '\0';
}
