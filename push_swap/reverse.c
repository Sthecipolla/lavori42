# include "push_swap.h"

static void reverse_rotate(t_lista ***list)
{
	t_lista *tmp;
	t_lista *tmp2;

	tmp = **list;
	tmp2 = **list;
	if(tmp == NULL || tmp->next == NULL)
		return ;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = **list;
	**list = tmp2;
}
void reverse_a(t_lista **list)
{
	reverse_rotate(&list);
}
void reverse_b(t_lista **list)
{
	reverse_rotate(&list);
}
void reverse_rr(t_lista **a, t_lista **b)
{
	reverse_rotate(&a);
	reverse_rotate(&b);
}
