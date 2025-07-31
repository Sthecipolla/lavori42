/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:43:30 by lhima             #+#    #+#             */
/*   Updated: 2024/11/26 12:19:29 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_len(char const *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

static void	fin(char *arr, char const *s1, int *i)
{
	int	i2;

	i2 = 0;
	while (s1[i2] != '\0')
	{
		arr[*i] = s1[i2];
		(*i)++;
		i2 ++;
	}
	arr[*i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *) malloc((ft_len(s1) + ft_len(s2)) + 1);
	if (!arr)
		return (NULL);
	fin (arr, s1, &i);
	fin (arr, s2, &i);
	return (arr);
}
