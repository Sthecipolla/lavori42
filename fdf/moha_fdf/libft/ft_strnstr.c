/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:50:52 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:50:53 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (j < len && big[j] != '\0')
	{
		k = 0;
		while (big[j + k] == little[k] && little[k] != '\0'
			&& (j + k) < len)
			k++;
		if (little[k] == '\0')
			return ((char *)(&big[j]));
		j++;
	}
	return (NULL);
}
/*int	main(int argc, char *argv[])
{
	if (argc == 4)
		printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", ft_strnstr("aaabcabcd", "aabc", -1));
	printf("%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	return (0);
}
*/
