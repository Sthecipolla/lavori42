/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:47:44 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:47:46 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (size * nmemb));
	return (s);
}
/*
int main(void)
{
	char *tmp = "ciao negri";

	char *string;
	printf("%p\n", string);
	string = ft_calloc(sizeof(int), strlen(tmp));
	//string = "fanculo";
	printf("%p\n", string);
	return (0);
}
*/
