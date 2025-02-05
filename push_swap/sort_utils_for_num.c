/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_for_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/05 16:49:11 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"



static void sort_stack_a(t_lista **a)
{
	/* t_lista *tmp;

	tmp = *a; */
/* 	while(tmp->num != find_min(*a))
		tmp = tmp -> next;
	add_cost(*a);
	if((*a) -> num != find_min(*a) && tmp->cost < 0)
	{
		while((*a) -> num != find_min(*a))
			reverse_a(a);
		return;
	} */
	while((*a) -> num != find_min(*a))
	{
		rotate_a(a);
	}
	print_arr(*a);
}

//source subject:
//reverse: The last element becomes the first one.
//rotate: The first element becomes the last one.

void move_stack(int cost_a,int cost_b,t_lista **a, t_lista **b)
{
	ft_printf("cost_a: %d\n", cost_a);
	ft_printf("cost_b: %d\n", cost_b);
	if(cost_a < 0 && cost_b < 0)
		reverse_rr(a, b);
	else if(cost_a > 0 && cost_b > 0)
		rotate_rr(a, b);
	else if(cost_b < 0)
		reverse_b(b);
	else if(cost_a < 0)
		reverse_a(a);
	else if(cost_a > 0)
		rotate_a(a);
	else if(cost_b > 0)
		rotate_b(b);
	add_cost(*a);
	add_cost(*b);
}

static int	ft_abs(int num1, int num2)
{
	if(num1 < 0)
		num1 = num1 * -1;
	if(num2 < 0)
		num2 = num2 * -1;
	return (num1 + num2);
}

void find_num_cost(t_lista **a, t_lista **b)
{
	t_lista *tmp_a;
	t_lista *tmp_b;
	int cost_a;
	int cost_b;
	t_cost	costs;

	costs.bestcost = len_split(*b) + len_split(*a);
	tmp_b = *b;
	while(tmp_b != NULL)
	{
		cost_b = (*b)->cost;
		tmp_a = *a;
		while(tmp_a != NULL)
		{
			cost_a = tmp_a->cost;
			if(tmp_a->num > tmp_b->num && costs.bestcost > ft_abs(cost_a, cost_b))
			{
				costs.bestcost = ft_abs(cost_a, cost_b);
				costs.cost_b = tmp_b->cost;
				costs.cost_a = tmp_a->cost;
				break;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
	move_stack(costs.cost_a,costs.cost_b, a, b);
	push_a(b, a);
	add_cost(*a);
	add_cost(*b);
	sort_stack_a(a);
}
