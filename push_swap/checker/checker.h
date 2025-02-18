#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"


typedef struct s_list
{
	int				num;
	struct s_list	*next;
}t_lista;


void	swap_a(t_lista *list);
void	swap_b(t_lista *list);
void	swap_ss(t_lista *list, t_lista *list2);
void	push_a(t_lista **a, t_lista **b);
void	push_b(t_lista **a, t_lista **b);
void	rotate_a(t_lista **list);
void	rotate_b(t_lista **list);
void	rotate_rr(t_lista **list, t_lista **list2);
void	reverse_a(t_lista **list);
void	reverse_b(t_lista **list);
void	reverse_rr(t_lista **list, t_lista **list2);
int		check_order(t_lista *l);
int		check_move(char *line, t_lista **a, t_lista **b);
int		check(char **arr);
int		fill_struc(t_lista *a, char **arr);
char	**fill(char **arr);
int		ft_atoi_long(const char *str);
#endif
