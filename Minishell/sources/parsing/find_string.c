/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:28 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:28:29 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

char	*cmd_add_error(char *str, int i)
{
	int	j;

	while (ft_isspace(str[i]) == TRUE && i > 0)
		i--;
	j = i;
	if (str[i] != '\0')
		i++;
	while (ft_isspace(str[j]) == FALSE && j > 0)
		j--;
	j++;
	if (ft_isspace(str[j]) == TRUE)
		return (ft_strdup(""));
	return (ft_substr(str, j, i - j));
}

static int	get_last_flag(t_cmd_line *arg)
{
	if (arg == NULL)
		return (ERROR);
	while (arg->next != NULL)
		arg = arg->next;
	return (arg->flag);
}

int	only_one(t_cmd_line *arg, char *str, int i, int flag)
{
	while (ft_isspace(str[i]) == TRUE)
		i++;
	if (get_last_flag(arg) == PIPE && str[i] == '|' && flag == EMPTY)
		return (TRUE);
	return (FALSE);
}
