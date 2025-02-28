/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:18 by lhima             #+#    #+#             */
/*   Updated: 2024/12/04 10:26:30 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_countba(const char *str, const char *set, int y)
{
	size_t	i;
	size_t	j;
	size_t	nset;

	i = y - 1;
	nset = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				nset++;
				break ;
			}
			else if (set[j + 1] == '\0')
				return (nset);
			j++;
		}
		i--;
	}
	return (nset);
}

static size_t	ft_countfw(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	nset;

	i = 0;
	nset = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				nset++;
				break ;
			}
			else if (set[j + 1] == '\0')
				return (nset);
			j++;
		}
		i++;
	}
	return (nset);
}

static void	fi(char *trimmed_str, int x, int y, const char *origin)
{
	int	i;

	i = 0;
	while (x <= y)
	{
		trimmed_str[i] = origin[x];
		x ++;
		i ++;
	}
	trimmed_str[i] = '\0';
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*trimmed_str;
	size_t	fv;
	size_t	ba;

	if (!str)
		return ((char *)(malloc(0)));
	if (!set)
		return (ft_strdup(str));
	fv = ft_countfw(str, set);
	if (fv == ft_strlen(str))
		return (ft_strdup("\0"));
	ba = ft_countba(str, set, ft_strlen(str));
	trimmed_str = (char *) malloc(sizeof(char) * \
	(ft_strlen(str) - ba - fv) + 1);
	if (trimmed_str == NULL)
		return (NULL);
	fi(trimmed_str, fv, ft_strlen(str) - ba - 1, str);
	return (trimmed_str);
}

/*
int main()
{
	//char *s1 = "ciao";
 	//char *s2 = "";
 	char *ret = ft_strtrim(NULL,NULL);

	printf("%s", ret);
	return (0);
}*/