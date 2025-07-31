/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:02:06 by lhima             #+#    #+#             */
/*   Updated: 2024/12/02 11:13:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*se;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' )
		i ++;
	se = (char *) malloc((i + 1) * sizeof(char));
	if (se == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' )
	{
		se[i] = s[i];
		i ++;
	}
	se[i] = '\0';
	return (se);
}
