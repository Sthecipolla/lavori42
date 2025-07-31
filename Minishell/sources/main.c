/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:11:33 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:08:57 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define TOO_MANY_ARGS_MSG "too many arguments"

static void	ft_prompt(t_shell *shell);
static void	command_management(t_shell *shell);

//variabile globale per i segnali
// serve quando esci dal cat here_doc ecc..
// per vedere con quale segnale e uscito da vedere come
int	g_sig_status = 0;

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	if (argc > 10)
		return (ft_dprintf(STDERR_FILENO, "%s: %s\n", PROG_NAME, \
			TOO_MANY_ARGS_MSG), ERR_GENERAL);
	if (def_signal(NULL) != 0)
		return (ERR_GENERAL);
	shell = ft_trash(env, argv);
	if (shell == NULL)
		exit(ERR_GENERAL);
	ft_prompt(shell);
	return (ft_cleanup(shell), EXIT_SUCCESS);
}

static void	ft_prompt(t_shell *shell)
{
	char	*pwd;

	while (TRUE)
	{
		pwd = getcwd(NULL, 0);
		pwd = ft_safe_strjoin(pwd, "$ ", 1);
		shell->str = readline(pwd);
		free(pwd);
		if (shell->str == NULL)
			ft_clean(shell, shell->exit_status);
		else if (shell->str[0] == '\0')
		{
			free(shell->str);
			shell->str = NULL;
			continue ;
		}
		if (g_sig_status == (SIGINT + 128))
			shell->exit_status = SIGINT + 128;
		add_history(shell->str);
		if (parsing(shell) == 0)
			continue ;
		command_management(shell);
	}
}

static void	command_management(t_shell *shell)
{
	if (shell == NULL)
		return ;
	if ((shell)->cmd_line == NULL)
		return ;
	g_sig_status = 0;
	ft_line_to_table(shell);
	if (shell->cmd_tables != NULL)
	{
		ft_exec_allcmd(shell);
		ft_return_to_prompt(shell);
	}
	if (shell->exit_status == (SIGQUIT + 128))
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	g_sig_status = 0;
}
