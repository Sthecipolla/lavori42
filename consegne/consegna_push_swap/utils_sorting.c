/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:00 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 13:44:16 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_lista *l)
{
	t_lista	*tmp;
	int		i;

	i = 0;
	tmp = l;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

int	find_max(t_lista *l)
{
	t_lista	*tmp;
	int		max;

	tmp = l;
	max = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_lista *l)
{
	t_lista	*tmp;
	int		min;

	tmp = l;
	min = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	close_max(int num, t_lista *a)
{
	t_lista	*tmp;
	int		close_max;

	tmp = a;
	close_max = find_max(a);
	if (close_max == num)
		return (num);
	while (tmp != NULL)
	{
		if (tmp->num < close_max && tmp->num > num)
			close_max = tmp->num;
		tmp = tmp->next;
	}
	return (close_max);
}
