/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:34:53 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 15:53:58 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "printf/ft_printf.h"
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_cost
{
	int				cost_b;
	int				bestcost;
	int				cost_a;
	int				num;
}					t_cost;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				cost;
}					t_lista;

int					check(char **arr);
void				free_double_pointer(char **ptr);
void				fill_struc(t_lista *list, char **str);
char				**fill(char **arr);
int					len_split(t_lista *list);
void				ft_clean(t_lista *list, int error);
void				swap_a(t_lista *list);
void				print_error(int error);
void				rotate_b(t_lista **list);
void				rotate_a(t_lista **list);
void				rotate_rr(t_lista **list, t_lista **list2);
void				reverse_a(t_lista **list);
void				reverse_b(t_lista **list);
void				reverse_rr(t_lista **list, t_lista **list2);
void				swap_b(t_lista *list);
void				swap_ss(t_lista *list, t_lista *list2);
void				push_a(t_lista **a, t_lista **b);
void				push_b(t_lista **a, t_lista **b);
long				ft_atoi_long(const char *nptr);
int					check_order(t_lista *l);
int					sorted_move(t_lista **a, t_lista **b);
int					find_max(t_lista *l);
int					find_min(t_lista *l);
int					before_three_sort(t_lista **a);
int					before_sorting_num(t_lista **a, t_lista **b);
void				find_num_cost(t_lista **a, t_lista **b);
void				add_cost(t_lista *list);
int					close_max(int num, t_lista *a);
int					calc_distance(int cost_a, int cost_b);
int					find_cost_of_a_num(t_lista *l, int num);
void				sort_stack_a(t_lista **a);

#endif
