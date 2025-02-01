/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/02/01 15:40:55 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	char **str;
	t_lista *list;
	t_lista *b;
	if(argc == 1)
	{
		write(2,"Error\nno arg\n",13);
		return (0);
	}
	str = fill(argv);
	check(str);
	list = ft_calloc(sizeof(t_lista),1);
	b = ft_calloc(sizeof(t_lista),1);
	b->len = 0;
	fill_struc(list, str);
	list->len = len_split(list);
	sorted_move(&list,&b);
	ft_clean(list, 100);
	return (0);
}
