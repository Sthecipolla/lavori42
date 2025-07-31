/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:03:18 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 22:21:35 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static void	ft_init_options(t_echo_options *options);
static int	parse_echo_options(char **args, t_echo_options *options);
static void	ft_print_echo(char **args, t_echo_options *options, int outfd);

void	builtin_echo(t_shell *shell, char **args, int flag, int outfd)
{
	t_echo_options	options;
	t_uchar			exit_code;

	exit_code = ERR_SUCCESS;
	ft_init_options(&options);
	if (args != NULL)
		ft_print_echo(args, &options, outfd);
	if (options.n == FALSE)
		write(outfd, "\n", 1);
	if (g_sig_status == (SIGPIPE + 128))
		exit_code = SIGPIPE + 128;
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	else
		return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}

static void	ft_init_options(t_echo_options *options)
{
	options->n = FALSE;
	options->e = FALSE;
}

/* static int	parse_echo_options(char **args, t_echo_options *options)
{
	size_t	i;
	size_t	j;

	j = 1;
	while (args[j] != NULL && args[j][0] == '-')
	{
		i = 1;
		while (args[j][i] != '\0' && args[j][i] == 'n')
			i++;
		if (i != ft_strlen(args[j]) || i == 1)
			return (j);
		i = 0;
		while (args[j][i] != '\0')
		{
			if (args[j][i] == 'e')
				options->e = TRUE;
			else if (args[j][i] == 'E')
				options->e = FALSE;
			else if (args[j][i] == 'n')
				options->n = TRUE;
			i++;
		}
		j++;
	}
	return (j);
} */

static int	parse_echo_options(char **args, t_echo_options *options)
{
	size_t	i;
	size_t	j;

	j = 1;
	while (args[j] != NULL && args[j][0] == '-')
	{
		i = 1;
		while (args[j][i] != '\0' && args[j][i] == 'n')
			i++;
		if (i != ft_strlen(args[j]) || i == 1)
			return (j);
		i = 0;
		while (args[j][i] != '\0')
		{
			if (args[j][i] == 'n')
				options->n = TRUE;
			i++;
		}
		j++;
	}
	return (j);
}

static void	ft_print_echo(char **args, t_echo_options *options, int outfd)
{
	size_t	i;
	size_t	j;

	i = parse_echo_options(args, options);
	j = i;
	while (args[i] != NULL)
	{
		if (i > j)
			write(outfd, " ", 1);
		ft_dprintf(outfd, "%s", args[i]);
		i++;
	}
}
