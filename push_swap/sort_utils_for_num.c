/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_for_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/06 16:43:36 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void sort_stack_a(t_lista **a)
{
	/* t_lista *tmp;

	tmp = *a;
	while(tmp->num != find_min(*a))
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

void move_stack(int *cost_a,int *cost_b,t_lista **a, t_lista **b)
{
 	ft_printf("cost_a = %d\n", *cost_a);
	ft_printf("cost_b = %d\n", *cost_b);
	if((*cost_a < 0 )&& (*cost_b < 0))
	{
		reverse_rr(a, b);
		*cost_a += 1;
		*cost_b += 1;

	}
	else if((*cost_a > 0) && (*cost_b > 0))
	{
		rotate_rr(a, b);
		*cost_a -= 1;
		*cost_b -= 1;
	}
	else if(*cost_b < 0)
	{
		reverse_b(b);
		*cost_b += 1;
	}
	else if(*cost_a < 0)
	{
		reverse_a(a);
		*cost_a += 1;
	}
	else if(*cost_a > 0)
	{
		rotate_a(a);
		*cost_a -= 1;
	}
	else if(*cost_b > 0)
	{
		rotate_b(b);
		*cost_b -= 1; 
	}
/* 	add_cost(*a);
	add_cost(*b); */
}

static int	ft_abs(int num1, int num2)
{
	if(num1 < 0)
		num1 = num1 * -1;
	if(num2 < 0)
		num2 = num2 * -1;
	return (num1 + num2);
}
void best_cost(t_lista **a, t_lista **b, t_cost *costs)
{
	t_lista *tmp_a;
	t_lista *tmp_b;
	int cost_a;
	int cost_b;

	tmp_b = *b;
	while(tmp_b != NULL)
	{
		cost_b = (*b)->cost;
		tmp_a = *a;
		while(tmp_a != NULL)
		{
			cost_a = tmp_a->cost;
			if(tmp_a->num > tmp_b->num && costs->bestcost > ft_abs(tmp_a->cost, tmp_b->cost))
			{
				costs->bestcost = ft_abs(cost_a, cost_b);
				costs->cost_b = tmp_b->cost;
				costs->cost_a = tmp_a->cost;
				break;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}
void find_num_cost(t_lista **a, t_lista **b)
{

	t_cost	costs;

	costs.bestcost = len_split(*b) + len_split(*a);
	if(find_max(*a) < (*b)->num)
	{
		push_a(b, a);
		rotate_a(a);
		add_cost(*a);
		add_cost(*b);
		return;
	}
	add_cost(*a);
	add_cost(*b);
	best_cost(a, b, &costs);
	ft_printf("cost_a = %d\n", costs.cost_a);
	ft_printf("cost_b = %d\n", costs.cost_b);
	while(costs.cost_a != 0 || costs.cost_b != 0)
		move_stack(&costs.cost_a, &costs.cost_b, a, b);
	best_cost(a, b, &costs);
	push_a(b, a);
	add_cost(*a);
	add_cost(*b);
	sort_stack_a(a);
}
