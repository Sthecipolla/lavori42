/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:34 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 17:04:05 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_pointer(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	len_split(t_lista *arr)
{
	int	x;

	x = 0;
	while (arr != NULL)
	{
		x++;
		arr = arr->next;
	}
	return (x);
}

void	ft_clean(t_lista *list, int error)
{
	t_lista	*tmp;

	if (list == NULL && error == 100)
		return ;
	if (list == NULL && error != 100)
		exit(0);
	if (error == 101)
		exit(0);
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	if (error == 100)
		return ;
	print_error(error);
	exit(0);
}
