/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:31:16 by lhima             #+#    #+#             */
/*   Updated: 2025/02/06 11:01:13 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int start_num_a(t_lista **a)
{
	t_lista *tmp;
	int count;
	int final;
	int app;
	int other;

	tmp = *a;
	count = 0;
	other = 0;
	app = tmp->num;
	while(tmp != NULL)
	{
		if(tmp -> num > app)
			count++;
		else if(other < count)
		{
			other = count;
			count = 0;
			final = tmp->num;
		}
		app = tmp->num;	
		tmp = tmp->next;		
	}
	return (final);
}
static int calc_seq(t_lista **a,int num)
{
	t_lista *tmp;
	int i;
	int app;

	tmp = *a;
	app = num;
	while(tmp->num != num)
		tmp = tmp->next;
	while(tmp != NULL || tmp->num >= app)
	{
		if(tmp->num < app)
			return (i);
		i++;
		tmp = tmp->next;
	}
} */

static int sorting(t_lista **a, t_lista **b)
{
	while(len_split(*a) != 5)
	{
		push_b(a, b);
	}
	before_five_sort(a,b);
	add_cost(*a);
	add_cost(*b);
	while(len_split(*b) != 0)
	{
		find_num_cost(a, b);
		add_cost(*a);
		add_cost(*b);
	}
	//print_arr(*a);
	sort_stack_a(a);
/* 	if(check_order(*a) == len_split(*a))
		ft_printf("OK\n");
	ft_printf("len:%d\n",len_split(*a)); */
	return (1);
}

int before_sorting_num(t_lista **a,t_lista **b)
{
	if(check_order(*a) == len_split(*a))
		return (0);
	return (sorting(a,b));
}
