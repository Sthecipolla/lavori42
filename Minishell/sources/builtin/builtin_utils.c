/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:34:16 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 12:04:54 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

t_uchar	check_options(char **args, char *func_name, int builtin_id)
{
	size_t	i;
	t_uchar	exit_code;

	i = 0;
	exit_code = ERR_SUCCESS;
	while (args[i] != NULL)
		i++;
	if (i > 1 && args[1][0] == '-' && args[1][1] != '\0')
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: -%c: %s\n", PROG_NAME, \
			func_name, args[1][1], INVALID_OPTION_MSG);
		if (builtin_id == ENV_BUILTIN)
			exit_code = ERR_INVOPT;
		else
			exit_code = ERR_BUILTIN;
	}
	else if ((i > 1 && builtin_id == ENV_BUILTIN) || \
		(i > 2 && builtin_id == CD_BUILTIN))
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", PROG_NAME, \
			func_name, TOO_MANY_ARGS_MSG);
		exit_code = ERR_GENERAL;
	}
	return (exit_code);
}

t_uchar	export_check_invalid_identifier(char *arg)
{
	t_uchar	exit_code;
	size_t	i;

	exit_code = ERR_SUCCESS;
	if (ft_isdigit(arg[0]) == TRUE || (ft_isalnum(arg[0]) == FALSE \
			&& arg[0] != '_'))
		exit_code = ERR_GENERAL;
	else
	{
		i = 0;
		while (arg[i] != '\0' && arg[i] != '=')
		{
			if ((ft_isalnum(arg[i]) == FALSE && arg[i] != '_' && \
					arg[i] != '+') || (arg[i] == '+' && arg[i + 1] != '='))
			{
				exit_code = ERR_GENERAL;
				break ;
			}
			i++;
		}
	}
	if (exit_code != ERR_SUCCESS)
		ft_dprintf(STDERR_FILENO, "%s: %s: `%s\': %s\n", PROG_NAME, \
			EXPORT_NAME, arg, INVALID_ID_MSG);
	return (exit_code);
}

t_uchar	unset_check_invalid_identifier(char *arg)
{
	t_uchar	exit_code;
	size_t	i;

	exit_code = ERR_SUCCESS;
	if (ft_isdigit(arg[0]) == TRUE || (ft_isalnum(arg[0]) == FALSE \
			&& arg[0] != '_'))
		exit_code = ERR_GENERAL;
	else
	{
		i = 0;
		while (arg[i] != '\0')
		{
			if (ft_isalnum(arg[i]) == FALSE && arg[i] != '_')
			{
				exit_code = ERR_GENERAL;
				break ;
			}
			i++;
		}
	}
	if (exit_code != ERR_SUCCESS)
		ft_dprintf(STDERR_FILENO, "%s: %s: `%s\': %s\n", PROG_NAME, \
			UNSET_NAME, arg, INVALID_ID_MSG);
	return (exit_code);
}

t_list	*node_of_variable_if_present(t_shell *shell, char *arg)
{
	char	*var_name;
	size_t	len_until_equal;
	t_list	*tmp;

	if (arg == NULL || shell == NULL)
		return (NULL);
	tmp = shell->envp;
	len_until_equal = 0;
	while (arg[len_until_equal] != '\0' && arg[len_until_equal] != '=' \
			&& arg[len_until_equal] != '+')
		len_until_equal++;
	var_name = ft_substr(arg, 0, len_until_equal);
	if (var_name == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), NULL);
	while (tmp != NULL)
	{
		if (ft_strncmp(var_name, (char *) tmp->content, len_until_equal) == 0 \
				&& (((char *) tmp->content)[len_until_equal] == '\0' || \
				((char *) tmp->content)[len_until_equal] == '='))
			return (free(var_name), tmp);
		tmp = tmp->next;
	}
	return (free(var_name), NULL);
}

void	*ft_void_strdup(void *p)
{
	char	*str;

	str = (char *) p;
	return ((void *) ft_strdup(str));
}
