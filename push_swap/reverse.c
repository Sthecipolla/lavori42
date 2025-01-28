# include "push_swap.h"

static void reverse(t_lista ***list)
{
	t_lista *tmp;
	t_lista *tmp2;

	if(**list == NULL || (**list)->next == NULL)
		return;
	tmp = **list;
	tmp2 = **list;
	while(tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = **list;
	**list = tmp;
}
void reverse_a(t_lista **list)
{
	reverse(&list);
}
void reverse_b(t_lista **list)
{
	reverse(&list);
}
void reverse_rr(t_lista **a, t_lista **b)
{
	reverse(&a);
	reverse(&b);
}