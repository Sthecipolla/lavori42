/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:28:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/15 13:59:52 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

#define OLDPWD "OLDPWD"
#define PWD "PWD"
#define HOME "HOME"
#define NOT_SET_MSG "not set"

static int	ft_cd_normal(t_shell *shell, char *arg, char *to_be_freed);
static char	*ft_get_var(char *var_name);
static int	ft_cd_minus(t_shell *shell, int outfd);
static int	ft_cd_home(t_shell *shell);

void	builtin_cd(t_shell *shell, char **args, int flag, int outfd)
{
	t_uchar	exit_code;
	size_t	i;

	exit_code = ERR_SUCCESS;
	if (args != NULL)
	{
		exit_code = check_options(args, CD_NAME, CD_BUILTIN);
		if (exit_code == ERR_SUCCESS)
		{
			i = 0;
			while (args[i] != NULL)
				i++;
			if (i < 2)
				exit_code = ft_cd_home(shell);
			else if (args[1][0] == '-' && args[1][1] == '\0')
				exit_code = ft_cd_minus(shell, outfd);
			else
				exit_code = ft_cd_normal(shell, args[1], NULL);
		}
	}
	if (g_sig_status == (SIGPIPE + 128))
		exit_code = SIGPIPE + 128;
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}

//	ft_simple_add is from export and adds a 
static int	ft_cd_normal(t_shell *shell, char *arg, char *to_be_freed)
{
	char	*oldpwd;
	char	*newpwd;

	oldpwd = ft_get_var(OLDPWD);
	if (oldpwd == NULL)
	{
		if (to_be_freed != NULL)
			free(to_be_freed);
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
	}
	if (chdir(arg) == -1)
		return (ft_dprintf(STDERR_FILENO, "%s: %s: %s: %s\n", PROG_NAME, \
			CD_NAME, arg, ft_strerror(errno)), free(oldpwd), ERR_GENERAL);
	newpwd = ft_get_var(PWD);
	if (newpwd == NULL)
	{
		if (to_be_freed != NULL)
			free(to_be_freed);
		return (free(oldpwd), ft_malloc_error(shell, ft_cleanup), \
			exit(errno), ERROR);
	}
	ft_simple_add(shell, oldpwd);
	ft_simple_add(shell, newpwd);
	return (free(newpwd), free(oldpwd), ERR_SUCCESS);
}

//	Don't free var_name
static char	*ft_get_var(char *var_name)
{
	char	*path;
	char	*tmp1;
	char	*tmp2;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (NULL);
	tmp1 = ft_strjoin(var_name, "=");
	if (tmp1 == NULL)
		return (free(path), NULL);
	tmp2 = ft_strjoin(tmp1, path);
	free(tmp1);
	if (tmp2 == NULL)
		return (free(path), NULL);
	free(path);
	return (tmp2);
}

static int	ft_cd_minus(t_shell *shell, int outfd)
{
	t_list	*variable;
	char	*str;
	char	*oldpwd;

	variable = node_of_variable_if_present(shell, OLDPWD);
	if (variable == NULL)
		return ((void) ft_dprintf(STDERR_FILENO, "%s: %s: %s %s\n", \
			PROG_NAME, CD_NAME, OLDPWD, NOT_SET_MSG), ERR_GENERAL);
	oldpwd = ft_strdup((char *) variable->content);
	if (oldpwd == NULL)
		return (ft_malloc_error(shell, ft_cleanup), ERROR);
	str = oldpwd;
	while (*str != '\0' && *str != '=')
		str++;
	if (*str == '\0' || (*str == '=' && *(str + 1) == '\0'))
		return (ft_dprintf(STDERR_FILENO, "%s: %s: %s %s\n", PROG_NAME, \
			CD_NAME, OLDPWD, NOT_SET_MSG), free(oldpwd), ERR_GENERAL);
	str++;
	ft_cd_normal(shell, str, oldpwd);
	free(oldpwd);
	str = getcwd(NULL, 0);
	if (str == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), -1);
	ft_dprintf(outfd, "%s\n", str);
	return (free(str), ERR_SUCCESS);
}

static int	ft_cd_home(t_shell *shell)
{
	t_list	*variable;
	char	*str;
	char	*home;

	variable = node_of_variable_if_present(shell, HOME);
	if (variable == NULL)
		return ((void) ft_dprintf(STDERR_FILENO, "%s: %s: %s %s\n", \
			PROG_NAME, CD_NAME, HOME, NOT_SET_MSG), ERR_GENERAL);
	home = ft_strdup((char *) variable->content);
	if (home == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), -1);
	str = home;
	while (*str != '\0' && *str != '=')
		str++;
	if (*str == '\0' || (*str == '=' && *(str + 1) == '\0'))
		return (ft_dprintf(STDERR_FILENO, "%s: %s: %s %s\n", \
			PROG_NAME, CD_NAME, HOME, NOT_SET_MSG), free(home), ERR_GENERAL);
	str++;
	ft_cd_normal(shell, str, home);
	free(home);
	return (ERR_SUCCESS);
}
