/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:15 by lhima             #+#    #+#             */
/*   Updated: 2024/12/14 14:50:08 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *c)
{
	size_t x;

	x = 0;
	while (c && c[x] != 0)
		x++;
	return (x);
}

static size_t ft_strtcpy(const char *s, char *cpy, size_t j)
{
	size_t i;

	i = 0;
	while (s && s[i])
	{
		cpy[j] = s[i];
		i++;
		j++;
	}
	return (j);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *str;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	i = i + (ft_strlen(s2));
	j = 0;
	str = (char *)ft_calloc((i + 1), 1);
	if (str == NULL)
		return (NULL);
	j = ft_strtcpy(s1, str, j);
	j = ft_strtcpy(s2, str, j);
	free(s1);
	str[i] = '\0';
	return (str);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *s;
	size_t i;

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

int ft_strncmp(const char *s1, const char *s2)
{

	unsigned char *p1;
	unsigned char *p2;
	int i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] == p2[i] && p1[i] != '\0' && p2[i] != '\0')
		i++;
	return ((unsigned char)p1[i] - p2[i]);
}
