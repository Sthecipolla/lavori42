# include "push_swap.h"

int calc_distance(int cost_a, int cost_b)
{
	if(cost_a < 0 && cost_b < 0)
	{
		if(cost_a < cost_b)
			return (cost_b - cost_a);
		return (cost_a - cost_b);
	}
	if(cost_b < 0)
		return (cost_a + cost_b);
	if(cost_a < 0)
		return ((cost_b + cost_a) * -1);
	if(cost_a > cost_b)
		return (cost_b - cost_a);
	return (cost_a - cost_b);
}

int find_cost_of_a_num(t_lista *l ,int num)
{
	t_lista *tmp;

	tmp = l;
	while(tmp != NULL)
	{
		if(tmp->num == num)
			return (tmp->cost);
		tmp = tmp->next;
	}
	return (tmp->cost);
}