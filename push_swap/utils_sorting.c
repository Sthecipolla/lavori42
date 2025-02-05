/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:00 by lhima             #+#    #+#             */
/*   Updated: 2025/02/04 10:17:19 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_order(t_lista *l)
{
	t_lista *tmp;
	int		i;

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
/*
int find_max(t_lista *l)
{
	t_lista *tmp;
	int		i;
	int		max;

	i = 0;
	tmp = l;
	max = ft_atoi(tmp->num);
	while(tmp->next != NULL)
	{
		if(ft_atoi(tmp->num) > max)
			max = ft_atoi(tmp->num);
		tmp = tmp->next;
		i ++;
	}
	return (max);
} */

int find_min(t_lista *l)
{
	t_lista *tmp;
	int		i;
	int		min;

	i = 0;
	tmp = l;
	min = tmp->num;
	while(tmp != NULL)
	{
		if(tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
		i ++;
	}
	return (min);
}
