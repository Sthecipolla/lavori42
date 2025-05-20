/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_print_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:49:46 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/15 15:38:32 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static void	ft_lstsort_ascii(t_list **lst);
static void	ft_print_envp_for_export(t_list *envp, int outfd);
static void	ft_write_var_content(char *str, int outfd);

void	ft_print_variables(t_shell *shell, int outfd)
{
	t_list	*envp_copy;

	envp_copy = ft_lstmap(shell->envp, ft_void_strdup, free);
	if (envp_copy == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno));
	ft_lstsort_ascii(&envp_copy);
	ft_print_envp_for_export(envp_copy, outfd);
	ft_lstclear(&envp_copy, free);
}

static void	ft_lstsort_ascii(t_list **lst)
{
	t_list	*c;
	int		sorted;
	void	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	sorted = FALSE;
	while (sorted == FALSE)
	{
		sorted = TRUE;
		c = *lst;
		while (c != NULL && c->next != NULL)
		{
			if (ft_strncmp((char *) c->content, (char *) c->next->content, \
				ft_strlen((char *) c->next->content) + 1) > 0)
			{
				tmp = c->content;
				c->content = c->next->content;
				c->next->content = tmp;
				sorted = FALSE;
			}
			c = c->next;
		}
	}
}

static void	ft_print_envp_for_export(t_list *envp, int outfd)
{
	char	*str;

	while (envp != NULL)
	{
		str = (char *) envp->content;
		if (ft_isdigit(*str) == TRUE)
		{
			envp = envp->next;
			continue ;
		}
		if (ft_dprintf(outfd, "declare -x ") == ERROR)
			break ;
		while (*str != '\0' && *str != '=')
		{
			write(outfd, str, 1);
			str++;
		}
		if (*str == '=')
			ft_write_var_content(str, outfd);
		write(outfd, "\n", 1);
		envp = envp->next;
	}
}

static void	ft_write_var_content(char *str, int outfd)
{
	write(outfd, str, 1);
	write(outfd, "\"", 1);
	while (*(++str) != '\0')
		write(outfd, str, 1);
	write(outfd, "\"", 1);
}
