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

static int	ft_abs(int num1, int num2)
{
	if(num1 < 0)
		num1 = num1 * -1;
	if(num2 < 0)
		num2 = num2 * -1;
	return (num1 + num2);
}

void cost_max_and_min(t_lista **a, t_lista **b, t_cost *costs, t_lista *tmp_b)
{
	if(costs->bestcost > ft_abs(find_cost_of_a_num(*a,find_min(*a)), \
	find_cost_of_a_num(*b,tmp_b->num)))
	{
		costs->bestcost = ft_abs(find_cost_of_a_num(*a,find_min(*a)), \
		find_cost_of_a_num(*b,tmp_b->num));
		costs->cost_b = find_cost_of_a_num(*b,tmp_b->num);
		costs->cost_a = find_cost_of_a_num(*a,find_min(*a));
		return;
	}
}

//source subject:
//reverse: The last element becomes the first one.
//rotate: The first element becomes the last one.

void move_stack(int *cost_a,int *cost_b,t_lista **a, t_lista **b)
{
	if((*cost_a < 0 )&& (*cost_b < 0))
		reverse_rr(a, b);
	else if((*cost_a > 0) && (*cost_b > 0))
		rotate_rr(a, b);
	else if(*cost_b < 0)
		reverse_b(b);
	else if(*cost_a < 0)
		reverse_a(a);
	else if(*cost_a > 0)
		rotate_a(a);
	else if(*cost_b > 0)
		rotate_b(b);
 	add_cost(*a);
	add_cost(*b);
}

void best_cost(t_lista **a, t_lista **b, t_cost *costs)
{
	t_lista *tmp_b;

	tmp_b = *b;
	while(tmp_b != NULL)
	{
		if(find_max(*a)< tmp_b->num)
			cost_max_and_min(a, b, costs, tmp_b);
		else if(costs->bestcost > ft_abs(find_cost_of_a_num(*a,close_max(tmp_b->num,*a)), \
		find_cost_of_a_num(*b,tmp_b->num)))
		{
			costs->bestcost = ft_abs(find_cost_of_a_num(*a,close_max(tmp_b->num,*a)), \
			find_cost_of_a_num(*b,tmp_b->num));
	//		ft_printf("bestcost = %d\n", costs->bestcost);
			costs->cost_b =  find_cost_of_a_num(*b,tmp_b->num);
			costs->cost_a = find_cost_of_a_num(*a,close_max( tmp_b->num,*a));
		}
		tmp_b = tmp_b->next;
	}
}
void find_num_cost(t_lista **a, t_lista **b)
{

	t_cost	costs;

	//ft_printf("lista a:\n");
	print_arr(*a);
	//ft_printf("lista b:\n");
	print_arr(*b);
 	costs.bestcost = len_split(*b) + len_split(*a);
	best_cost(a, b, &costs);
	/* if(costs.bestcost > calc_distance(costs.cost_a, costs.cost_b))
		rotate_b_until_right(b, costs.cost_a, find_min(*a)); */
	while(costs.cost_a != 0 || costs.cost_b != 0)
		{
	//	ft_printf("cost_a = %d cost_b = %d\n", costs.cost_a, costs.cost_b);
		move_stack(&costs.cost_a, &costs.cost_b, a, b);
		best_cost(a, b, &costs);
		}
	push_a(b, a);
	//sort_stack_a(a);
	add_cost(*a);
	add_cost(*b);
	//ft_printf("lista a:\n");
	//print_arr(*a);
	//ft_printf("lista b:\n");
	//print_arr(*b);
}
