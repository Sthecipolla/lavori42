#include "checker.h"

int	check_move(char *line, t_lista **a, t_lista **b)
{
	if(ft_strncmp(line, "sa", 2) == 0)
		sa(a);
	else if(ft_strncmp(line, "sb", 2) == 0)
		sb(b);
	else if(ft_strncmp(line, "ss", 2) == 0)
		ss(a, b);
	else if(ft_strncmp(line, "pa", 2) == 0)
		pa(a, b);
	else if(ft_strncmp(line, "pb", 2) == 0)
		pb(a, b);
	else if(ft_strncmp(line, "ra", 2) == 0)
		ra(a);
	else if(ft_strncmp(line, "rb", 2) == 0)
		rb(b);
	else if(ft_strncmp(line, "rr", 2) == 0)
		rr(a, b);
	else if(ft_strncmp(line, "rra", 3) == 0)
		rra(a);
	else if(strncmp(line, "rrb", 3) == 0)
		rrb(b);
	else if(ft_strncmp(line,"rrr",3) == 0)
		rrr(a, b);
	else
		return (1);
	return (0);
}
