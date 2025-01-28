/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:34 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 17:06:15 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
	int x;

	x = 0;
	while(arr != NULL)
	{
		x++;
		arr = arr->next;
	}
	return (x);
}

void ft_clean(t_lista *t_list, int error)
{
	t_lista *tmp;

	print_error(error);
	if(t_list == NULL)
		exit(0);
	while(t_list->next != NULL)
	{
		tmp = t_list->next;
		free(t_list);
		t_list = tmp;
	}
	exit(0);
}
