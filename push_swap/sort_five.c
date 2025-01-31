# include "push_swap.h"

static int check_if_last(t_lista **a)
{
	t_lista *tmp;

	tmp = *a;
	while(tmp->next != NULL)
		tmp = tmp->next;
	if(tmp->num == find_min(*a))
	{
		ft_printf("rra\n");
		reverse_a(&(*a));
		return (1);
	}
	return (0);
}

static int sorter_five(t_lista **a)
{
	t_lista *b;
	int i;

	i = 0;
	while(len_split((*a)) != 4)
	{
		i++;
		i+=check_if_last(&(*a));
		if((*a)->num == find_min((*a)))
		{
			ft_printf("pb\n");
			push_b(&(*a), &b);
		}
		else
		{
			ft_printf("ra\n");
			rotate_a(&(*a));
		}
	}
	i+=before_four_sort(&(*a));
	push_a(&b, &(*a));
	ft_printf("pa\n");
	i++;
	return (i);
}


int before_five_sort(t_lista **a)
{
	if(check_order(*a) == 4)
		return (0);
	return (sorter_five(&(*a)));
}