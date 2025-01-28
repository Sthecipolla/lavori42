/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:37 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 16:46:46 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	check_swap_a(t_lista *t_lista)
{
	if(t_lista == NULL)
		ft_clean(t_lista, 1);
	if(len_split(t_lista) < 2)
		ft_clean(t_lista, 1);
}

static void print_arr(t_lista *t_lista)
{

	while(t_lista != NULL)
	{
		ft_printf("%s ", t_lista->num);
		t_lista = t_lista->next;
	}
	ft_printf("\n");
}
void swap_a(t_lista *t_lista)
{
	check_swap_a(t_lista);
	ft_printf("before:\n");
	print_arr(t_lista);
	ft_printf("after:\n");
	char *t;
	t = t_lista->num;
	t_lista->num = t_lista->next->num;
	t_lista->next->num = t;
	ft_printf("swap first 2 num\n");
	print_arr(t_lista);
}
