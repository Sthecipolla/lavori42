/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:47:08 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:18:23 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

#define WARNING "warning"
#define HERE_DOC_MSG "here-document delimited by end-of-file"

int	ft_strcheck(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	write_here_doc(char *limi)
{
	char	*str;
	int		fd;

	fd = dup(STDIN_FILENO);
	while (1)
	{
		str = readline("> ");
		if (g_sig_status == 130)
		{
			dup2(fd, STDIN_FILENO);
			break ;
		}
		if (str == NULL)
		{
			ft_dprintf(STDERR_FILENO, "%s: %s: %s (wanted `%s\')\n", PROG_NAME,
				WARNING, HERE_DOC_MSG, limi);
			break ;
		}
		if (ft_strcheck(limi, str, ft_strlen(limi)) == 0)
			break ;
		free(str);
	}
	return (close(fd), free(str));
}

int	count_here_doc(t_cmd_line *cmd, int len)
{
	int	i;
	int	count_element;

	i = 0;
	count_element = 0;
	while (len > i && cmd != NULL)
	{
		if ((cmd->flag == HERE_DOC || cmd->flag == HERE_DOC_NE) && i + 1 < len)
			count_element++;
		i++;
		cmd = cmd->next;
	}
	return (count_element);
}

void	*ft_here_doc(char **matrix, t_shell *tr)
{
	int	i;

	i = 0;
	ft_manage_sigint_heredoc(tr);
	while (matrix[i] != NULL)
	{
		write_here_doc(matrix[i]);
		i++;
		if (g_sig_status == 130)
		{
			tr->exit_status = g_sig_status;
			g_sig_status = 0;
			break ;
		}
	}
	return (free(matrix), def_signal(tr), "");
}
