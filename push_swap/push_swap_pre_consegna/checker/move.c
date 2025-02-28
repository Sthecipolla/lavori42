#include "checker.h"

int	check_move(char *line, t_lista **a, t_lista **b)
{
	if(ft_strncmp(line, "sa", 2) == 0)
		swap_a((*a));
	else if(ft_strncmp(line, "sb", 2) == 0)
		swap_b((*b));
	else if(ft_strncmp(line, "ss", 2) == 0)
		swap_ss((*a), (*b));
	else if(ft_strncmp(line, "pa", 2) == 0)
		push_a(a, b);
	else if(ft_strncmp(line, "pb", 2) == 0)
		push_b(a, b);
	else if(ft_strncmp(line, "ra", 2) == 0)
		rotate_a(a);
	else if(ft_strncmp(line, "rb", 2) == 0)
		rotate_b(b);
	else if(ft_strncmp(line, "rr", 2) == 0)
		rotate_rr(a, b);
	else if(ft_strncmp(line, "rra", 3) == 0)
		reverse_a(a);
	else if(strncmp(line, "rrb", 3) == 0)
		reverse_b(b);
	else if(ft_strncmp(line,"rrr",3) == 0)
		reverse_rr(a, b);
	else
		return (1);
	return (0);
}
