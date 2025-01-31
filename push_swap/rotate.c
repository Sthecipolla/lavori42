# include "push_swap.h"

static void rotate(t_lista **list)
{
	t_lista *tmp;
	t_lista *tmp2;

	if(*list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	tmp2 = *list;
	*list = (*list)->next;
	while(tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}
void rotate_a(t_lista **list)
{
	rotate(&(*list));
}
void rotate_b(t_lista **list)
{
	rotate(&(*list));
}
void rotate_rr(t_lista **a, t_lista **b)
{
	rotate(&(*a));
	rotate(&(*b));
}
//porta in fondo il primo elemento della lista
