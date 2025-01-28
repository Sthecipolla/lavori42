/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:37 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 17:34:19 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	check_swap_a(t_lista *list)
{
	if(list == NULL)
		ft_clean(list, 1);
	if(len_split(list) < 2)
		ft_clean(list, 1);
}

static void print_arr(t_lista *list)
{

	while(list != NULL)
	{
		ft_printf("%s ", list->num);
		list = list->next;
	}
	ft_printf("\n");
}
void swap_a(t_lista *list)
{
	check_swap_a(list);
	ft_printf("before:\n");
	print_arr(list);
	ft_printf("after:\n");
	char *t;
	t = list->num;
	list->num = list->next->num;
	list->next->num = t;
	ft_printf("swap first 2 num\n");
	print_arr(list);
}
