/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:11:58 by lhima             #+#    #+#             */
/*   Updated: 2024/12/03 13:44:15 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	str_len;
	size_t	start1;

	str_len = 0;
	start1 = (size_t)start;
	if (s == NULL)
		return (NULL);
	while (s[str_len])
		str_len++;
	if (str_len <= start1)
		return (ft_strdup(""));
	if (start1 + len > str_len)
		len = str_len - start1;
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start1, len + 1);
	return (dest);
}
/*int main()
{
	char const *s = "riccardo";
	int start = 10;
	int end = 2;
	char *res = ft_substr(s, start, end);
	if(res)
		free(res);
	(void)res;
}*/
