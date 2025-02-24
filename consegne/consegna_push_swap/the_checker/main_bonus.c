/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:25 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 18:26:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	things(char **argv, t_lista **a, t_lista **b)
{
	char	**str;

	str = fill(argv);
	check(str);
	*a = ft_calloc(sizeof(t_lista), 1);
	fill_struc(*a, str);
	*b = NULL;
}

void	still_norm(char *line, t_lista **a, t_lista **b)
{
	if (check_move(line, a, b) == 1)
	{
		ft_clean(*a, 100);
		if (line != NULL)
			free(line);
		ft_clean(*b, 1);
	}
}

int	main(int argc, char **argv)
{
	t_lista		*a;
	t_lista		*b;
	char		*line;

	if (argc < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	things(argv, &a, &b);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_move(line, &a, &b) == 1)
			still_norm(line, &a, &b);
		if (line != NULL)
			free(line);
		line = get_next_line(0);
	}
	if (check_order(a) == len_split(a) && b == NULL)
		ft_printf("OK\n");
	else
		write(1, "KO\n", 3);
	ft_clean(a, 100);
	ft_clean(b, 0);
	return (0);
}
