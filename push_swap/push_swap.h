#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include "./libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_list
{
	char	*num;
	struct s_list	*next;
}t_lista;


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
//da cancellare
void print_arr(t_lista *list);
//



#endif
