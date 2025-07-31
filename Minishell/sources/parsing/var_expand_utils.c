/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:07:38 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/12 11:56:40 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

int	vl_ch_en(char c)
{
	if (c == '_' || ft_isalnum(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

char	*status(int exit_status)
{
	static char	buffer[12];
	int			i;

	i = 10;
	if (exit_status == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	buffer[11] = '\0';
	while (exit_status > 0 && i >= 0)
	{
		buffer[i] = (exit_status % 10) + '0';
		exit_status /= 10;
		i--;
	}
	return (&buffer[i + 1]);
}
