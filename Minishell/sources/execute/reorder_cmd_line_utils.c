/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_cmd_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:19:25 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

int	ft_isredir(int flag)
{
	if (flag == REDIR_IN || flag == REDIR_OUT || flag == RED_APPEND \
			|| flag == HERE_DOC || flag == HERE_DOC_NE)
		return (TRUE);
	return (FALSE);
}

void	ft_conc_cmdline(t_cmd_line **l, t_cmd_line *conc)
{
	t_cmd_line	*tmp;

	if (l == NULL)
		return ;
	if (*l == NULL)
		*l = conc;
	else
	{
		tmp = *l;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = conc;
	}
}

int	ft_dup_add_node(t_shell *s, t_cmd_line **lst, t_cmd_line *toadd)
{
	char	*str;

	str = ft_strdup(toadd->str);
	if (str == NULL)
		return (ft_free_cmd_line(lst), \
			ft_malloc_error(s, ft_cleanup), ERROR);
	if (ft_add_node(lst, str, toadd->flag) == NULL)
		return (free(str), ft_free_cmd_line(lst), \
			ft_malloc_error(s, ft_cleanup), ERROR);
	return (ERR_SUCCESS);
}
