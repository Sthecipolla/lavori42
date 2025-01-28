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
int		len_split(t_lista *list);
void	ft_clean(t_lista *list,int error);
void	swap_a(t_lista *list);
void	print_error(int error);

#endif
