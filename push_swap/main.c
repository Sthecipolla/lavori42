/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/29 12:02:29 by lhima            ###   ########.fr       */
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
		ft_printf("Error\nno arg\n");
		return (0);
	}
	str = fill(argv);
	check(str);
	list = ft_calloc(sizeof(t_lista),1);
	b = NULL;
	fill_struc(list, str);
	ft_clean(list, 100);
	ft_clean(b, 0);
	return (0);
}
