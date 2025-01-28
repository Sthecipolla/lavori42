/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 17:50:08 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc, char **argv)
{
	char **str;
	t_lista *list;

	if(argc == 1)
	{
		ft_printf("Error\narg\n");
		return (0);
	}
	str = fill(argv);
	check(str);
	list = ft_calloc(sizeof(t_lista),1);
	fill_struc(list, str);
	swap_a(list);
	ft_clean(list, 0);
	return (0);
}
