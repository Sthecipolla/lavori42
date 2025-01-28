/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:42:48 by lhima             #+#    #+#             */
/*   Updated: 2025/01/23 10:21:20 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_arr_split(char	const *arr, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!arr)
		return (0);
	while (arr[x] != '\0')
	{
		if ((arr[x] == c && arr[x + 1] != c && \
		arr[x + 1] != '\0') || (x == 0 && arr[x] != c))
			i++;
		x++;
	}
	return (i);
}

static void	refill(char *dest, int start, int lenword, char const *string)
{
	int	i;

	i = 0;
	while (i + start < start + lenword)
	{
		dest[i] = string[start + (i)];
		i++;
	}
	dest[i] = '\0';
}

static	char	**fill(char **dest, char c, char const *string, int bro)
{
	int	i;
	int	x;
	int	conta;
	int	y;

	x = 0;
	i = 0;
	y = 0;
	while (x < bro)
	{
		conta = 1;
		while (string[i++] == c)
			;
		y = i;
		while (string[y] != '\0' && string[y++] != c)
			conta++;
		dest[x] = (char *) malloc(sizeof(char) * (conta + 1));
		if (dest[x] == NULL)
			return (NULL);
		refill(dest[x++], i - 1, conta, string);
		while (string[y] != '\0' && string[i++] != c)
			;
	}
	dest[x] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		x;
	int		nwords;

	x = 0;
	dest = NULL;
	nwords = (len_arr_split(s, c));
	dest = (char **) malloc((nwords + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (fill(dest, c, s, (len_arr_split(s, c))) == NULL)
	{
		while (x ++ <= (len_arr_split(s, c)))
			free(dest[x]);
		free(dest);
		return (NULL);
	}
	return (dest);
}
