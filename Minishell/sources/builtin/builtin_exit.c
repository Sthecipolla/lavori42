/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:07:55 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/16 12:03:59 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static t_uchar	get_error_code(t_shell *shell, char **args, int *num_err_flag);
static int		ft_check_err_numeric(t_shell *shell, char **args);
static int		ft_check_err_long_overflow(t_shell *shell, char *arg);

void	builtin_exit(t_shell *shell, char **args, int flag)
{
	t_uchar	exit_code;
	size_t	i;
	int		numeric_err_flag;

	exit_code = shell->exit_status;
	numeric_err_flag = FALSE;
	if (args != NULL)
	{
		if (flag == PARENT)
			if (write(STDERR_FILENO, "exit\n", 5) == -1)
				perror ("write");
		exit_code = get_error_code(shell, args, &numeric_err_flag);
		i = 0;
		while (args[i] != NULL)
			i++;
		if (flag == CHILD)
			return (ft_cleanup(shell), exit(exit_code));
		else if (flag == PARENT && numeric_err_flag == FALSE && i > 2)
			return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
	}
	return (ft_cleanup(shell), exit(exit_code));
}

static t_uchar	get_error_code(t_shell *shell, char **args, int *num_err_flag)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	*num_err_flag = ft_check_err_numeric(shell, args);
	if (*num_err_flag == TRUE)
	{
		if (ft_dprintf(STDERR_FILENO, "%s: %s: %s: %s\n", \
			PROG_NAME, EXIT_NAME, args[1], EXIT_NUMERIC_MSG) == -1)
			perror("write");
		return (ERR_BUILTIN);
	}
	else if (i > 2)
	{
		if (ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", \
			PROG_NAME, EXIT_NAME, TOO_MANY_ARGS_MSG) == -1)
			perror("write");
		return (ERR_GENERAL);
	}
	if (args[1] == NULL)
		return ((t_uchar) shell->exit_status);
	return ((t_uchar) ft_atol(args[1]));
}

static int	ft_check_err_numeric(t_shell *shell, char **args)
{
	char	*tmp;
	size_t	i;

	if (args == NULL)
		return (FALSE);
	i = 0;
	while (args[i] != NULL)
		i++;
	if (i < 2)
		return (FALSE);
	tmp = args[1];
	if (*tmp == '\0')
		return (TRUE);
	if (*tmp == '-')
		tmp++;
	while (*tmp != '\0')
	{
		if (ft_isdigit(*tmp) == FALSE)
			return (TRUE);
		tmp++;
	}
	if (ft_check_err_long_overflow(shell, args[1]) == TRUE)
		return (TRUE);
	return (FALSE);
}

static int	ft_check_err_long_overflow(t_shell *shell, char *arg)
{
	char	*limit;

	if (*arg == '-')
		limit = ft_ltoa(LONG_MIN);
	else
		limit = ft_ltoa(LONG_MAX);
	if (limit == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), TRUE);
	if (ft_strlen(limit) < ft_strlen(arg))
		return (free(limit), TRUE);
	else if (ft_strlen(limit) == ft_strlen(arg) && \
		ft_strncmp(arg, limit, ft_strlen(limit) + 1) > 0)
		return (free(limit), TRUE);
	return (free(limit), FALSE);
}

/* 
HOW TO EXIT THE PROGRAM
if (numero comand == 0 && conteggio totale dei comandi == 1)
	allora lancia exit builtin senza forkare e senza fare pipe;
*/
