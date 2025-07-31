/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:00 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 11:26:04 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_order(t_lista *l)
{
	t_lista *tmp;
	int		i;

	if(l == NULL)
		return (0);
	i = 0;
	tmp = l;
	while(tmp->next != NULL)
	{
		if(tmp->num > tmp->next->num)
			return (i);
		tmp = tmp->next;
		i ++;
	}
	return (i + 1);
}

int find_max(t_lista *l)
{
	t_lista *tmp;
	int		max;

	tmp = l;
	max = tmp->num;
	while(tmp != NULL)
	{
		if(tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int find_min(t_lista *l)
{
	t_lista *tmp;
	int		min;

	tmp = l;
	min = tmp->num;
	while(tmp != NULL)
	{
		if(tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}
//return num if there are no min number
int close_min(int num, t_lista *a)
{
	t_lista *tmp;
	int		close_min;

	tmp = a;
	close_min = find_min(a);
	if(close_min == num)
		return (num);
	while(tmp != NULL)
	{
		if(!(tmp->num < close_min) && tmp->num < num)
			close_min = tmp->num;
		tmp = tmp->next;
	}
	return (close_min);
}
//return num if there are no max number
int close_max(int num, t_lista *a)
{
	t_lista *tmp;
	int		close_max;

	tmp = a;
	close_max = find_max(a);
	if(close_max == num)
		return (num);
	while(tmp != NULL)
	{
		if(tmp->num < close_max && tmp->num  > num)
			close_max = tmp->num;
		tmp = tmp->next;
	}
	return (close_max);
}


void sort_stack_a(t_lista **a)
{
	t_lista *tmp;
	int cost;

	tmp = *a;
	while(tmp->num != find_min(*a))
		tmp = tmp -> next;
	cost = tmp->cost;
	if(cost < 0)
	{
		while(cost++ != 0)
			reverse_a(a);
		return;
	}
	while(cost-- != 0)
		rotate_a(a);
	print_arr(*a);
}
/* int main()
{
	t_lista *p;
	p = calloc(1, sizeof(t_lista));
	t_lista *tmp = p;

	int i = 1;
	while(i < 10)
	{
		if(i%2 == 0)
			tmp->num = i;
		else
			tmp->num = i*3;
		tmp-> next= calloc(1, sizeof(t_lista));
		tmp->next->next = NULL;
		tmp = tmp->next;
		i++;
	}
	rotate_a(&p);
	rotate_a(&p);
	rotate_a(&p);
	tmp = p;
	while(tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	printf("max: %d\n", close_max(3, p));
	printf("min:%d\n", close_min(3, p));

	return 0;
} */
