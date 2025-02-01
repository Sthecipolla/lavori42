
# include "push_swap.h"

static void push(t_lista **to_take, t_lista **to_add)
{
	t_lista *tmp;

	if(*to_take == NULL)
		return;
	tmp = *to_take;
	*to_take = (*to_take)->next;
	tmp->next = *to_add;
	*to_add = tmp;
}
void push_a(t_lista **b, t_lista **a)
{
	if((*b)->len == 0)
		return;
	push(b, a);
	ft_printf("pa\n");
	(*b)->len--;
	(*a)->len++;
}
void push_b(t_lista **a, t_lista **b)
{
	if((*a)->len == 0)
		return;
	push(a, b);
	ft_printf("pb\n");
	(*b)->len++;
	(*a)->len--;
}
