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
	rotate(list);
	ft_printf("ra\n");
}
void rotate_b(t_lista **list)
{
	rotate(list);
	ft_printf("rb\n");
}
void rotate_rr(t_lista **a, t_lista **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
//porta in fondo il primo elemento della lista
