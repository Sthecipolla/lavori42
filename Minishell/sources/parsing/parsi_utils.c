/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsi_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:18 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 14:02:40 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static int	count_h(char *str)
{
	int	count;
	int	index;

	index = ft_strlen(str) - 1;
	count = 0;
	if (index == -1)
		return (TRUE);
	while (index > 0 && str[index] == '$')
	{
		count++;
		index--;
	}
	if (str[index] == '$')
		count++;
	if (count % 2 == 0)
		return (TRUE);
	return (FALSE);
}

char	*normal_str(t_shell *t, char *str, int *i, char *app)
{
	char	*n_str;

	n_str = (char *)ft_calloc(1, sizeof(char));
	if (n_str == NULL)
		return (free(app), NULL);
	while (str[*i] != '\'' && str[*i] != '\"' && str[*i] != '\0'
		&& ft_isspace(str[*i]) == FALSE)
	{
		if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
			break ;
		if (str[*i] == '$' && (str[*i + 1] == '\'' || str[*i + 1] == '\"') && \
			((count_h(n_str) == TRUE && last_node_h(t->cmd_line, 0) == TRUE) \
			|| last_node_h(t->cmd_line, 0) == FALSE))
		{
			(*i)++;
			break ;
		}
		if (ft_add_char(&n_str, str[*i]) == NULL)
			return (free(app), NULL);
		(*i)++;
	}
	if (last_node_h(t->cmd_line, FALSE) == FALSE)
		n_str = there_are_spaces(n_str, t, &app, 0);
	return (free(app), n_str);
}

int	last_node_h(t_cmd_line *cmd, int change)
{
	if (cmd == NULL)
		return (FALSE);
	while (cmd->next != NULL)
		cmd = cmd->next;
	if (cmd->flag == HERE_DOC && change == TRUE)
		cmd->flag = HERE_DOC_NE;
	if (cmd->flag == HERE_DOC || cmd->flag == HERE_DOC_NE)
		return (TRUE);
	return (FALSE);
}

int	last_node_re(t_cmd_line *cmd)
{
	if (cmd == NULL)
		return (FALSE);
	while (cmd->next != NULL)
		cmd = cmd->next;
	if (cmd->flag == REDIR_IN || cmd->flag == REDIR_OUT)
		return (TRUE);
	if (cmd->flag == RED_APPEND)
		return (TRUE);
	return (FALSE);
}
