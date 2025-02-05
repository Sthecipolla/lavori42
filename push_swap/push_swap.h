#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include "./libft/libft.h"
# include "printf/ft_printf.h"


typedef struct s_cost
{
	int		cost_b;
	int		bestcost;
	int		cost_a;
	int		flag;
}t_cost;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				cost;
}t_lista;

//da cancellare
void print_arr(t_lista *list);
//da cancellare
int		check(char **arr);
void	free_double_pointer(char **ptr);
void	fill_struc(t_lista *list, char **str);
char	**fill(char **arr);
int		len_split(t_lista *list);
void	ft_clean(t_lista *list,int error);
void	swap_a(t_lista *list);
void	print_error(int error);
void	rotate_b(t_lista **list);
void	rotate_a(t_lista **list);
void	rotate_rr(t_lista **list, t_lista **list2);
void	reverse_a(t_lista **list);
void	reverse_b(t_lista **list);
void	reverse_rr(t_lista **list, t_lista **list2);
void	swap_b(t_lista *list);
void	swap_ss(t_lista *list, t_lista *list2);
void	push_a(t_lista **a, t_lista **b);
void	push_b(t_lista **a, t_lista **b);
long	ft_atoi_long(const char *nptr);
int		check_order(t_lista *l);
int		sorted_move(t_lista **a, t_lista **b);
int		find_min(t_lista *l);
//int		order_num_three(t_lista **list, int i);
int		before_four_sort(t_lista **a, t_lista **b);
int		before_three_sort(t_lista **a);
int before_five_sort(t_lista **a, t_lista **b);
int before_sorting_num(t_lista **a,t_lista **b);
void find_num_cost(t_lista **a, t_lista **b);
void add_cost(t_lista *list);




#endif
