/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_cmd_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:03:17 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:21:25 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

t_cmd_line	*ft_redir_lst(t_shell *s, t_cmd_line *line, t_cmd_line **f);
t_cmd_line	*ft_cmd_lst(t_shell *s, t_cmd_line *line, t_cmd_line **f);
t_cmd_line	*ft_cmdlinelast(t_cmd_line *lst);

void	reorder_cmd_line(t_shell *s, t_cmd_line *line)
{
	t_cmd_line	*ret;

	ret = NULL;
	while (line != NULL)
	{
		if (line != NULL && line->flag != PIPE)
		{
			ft_conc_cmdline(&ret, ft_redir_lst(s, line, &ret));
			ft_conc_cmdline(&ret, ft_cmd_lst(s, line, &ret));
			while (line != NULL && line->flag != PIPE)
				line = line->next;
		}
		else if (line != NULL && line->flag == PIPE)
		{
			if (ft_dup_add_node(s, &ret, line) != ERR_SUCCESS)
				return (ft_free_cmd_line(&ret), \
					ft_malloc_error(s, ft_cleanup), exit(errno));
			line = line->next;
		}
	}
	ft_free_cmd_line(&(s->cmd_line));
	s->cmd_line = ret;
}

t_cmd_line	*ft_redir_lst(t_shell *s, t_cmd_line *line, t_cmd_line **f)
{
	t_cmd_line	*redirs;

	redirs = NULL;
	while (line != NULL && line->flag != PIPE)
	{
		if (ft_isredir(line->flag) == TRUE)
		{
			if (ft_dup_add_node(s, &redirs, line) != ERR_SUCCESS)
				return (ft_free_cmd_line(f), exit(errno), NULL);
			line = line->next;
			if (line == NULL || line->flag == PIPE)
				break ;
			if (ft_dup_add_node(s, &redirs, line) != ERR_SUCCESS)
				return (ft_free_cmd_line(f), exit(errno), NULL);
		}
		line = line->next;
	}
	return (redirs);
}

t_cmd_line	*ft_cmd_lst(t_shell *s, t_cmd_line *line, t_cmd_line **f)
{
	t_cmd_line	*cmds;
	size_t		count;

	cmds = NULL;
	count = 0;
	while (line != NULL && line->flag != PIPE)
	{
		if (ft_isredir(line->flag) == TRUE && line->next != NULL)
			line = line->next->next;
		else
		{
			if (ft_dup_add_node(s, &cmds, line) != ERR_SUCCESS)
				return (ft_free_cmd_line(f), exit(errno), NULL);
			count++;
			if (count > 1)
				ft_cmdlinelast(cmds)->flag = ARG;
			line = line->next;
		}
	}
	return (cmds);
}

t_cmd_line	*ft_cmdlinelast(t_cmd_line *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
