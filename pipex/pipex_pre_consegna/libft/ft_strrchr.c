/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:57:11 by lhima             #+#    #+#             */
/*   Updated: 2024/12/02 16:30:16 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				s2;
	unsigned char	c2;

	i = 0;
	s2 = 0;
	c2 = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (c2 == s[i])
			s2 = i;
		i ++;
	}
	if (c2 == s[i])
		s2 = i;
	if (c2 == s[s2])
		return ((char *)&s[s2]);
	return (NULL);
}

/*int main()
{
	printf("%s",ft_strrchr("teste",1125));

	return (0);
}*/