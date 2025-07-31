/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:54:37 by lhima             #+#    #+#             */
/*   Updated: 2025/02/28 11:22:09 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	for_the_forking(pid_t *childpid)
{
	*childpid = fork();
	if (*childpid == -1)
	{
		ft_putstra_fd("error\n", 2);
		exit(1);
	}
	return (0);
}

void	argc_check_and_fd(int argc, int *file, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
	{
		ft_putstra_fd("error\n", 2);
		exit(1);
	}
	while (argv[i] != NULL && argv[i][0] != '\0')
		i++;
	if (argv[i] != NULL && argv[i][0] == '\0')
	{
		ft_putstra_fd("error\n", 2);
		exit(14);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file[0] == -1 || file[1] == -1)
	{
		close(file[0]);
		close(file[1]);
		ft_putstra_fd("error\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex		p;
	pid_t		childpid;
	int			i;

	i = -1;
	argc_check_and_fd(argc, p.file, argv);
	dup2(p.file[0], 0);
	close(p.file[0]);
	while (argc - 4 > ++i)
	{
		pipe(p.fd);
		for_the_forking(&childpid);
		if (childpid == 0 && i == 0)
			first_command(argv, envp, p);
		else if (childpid == 0 && i != 0)
			command(argv, envp, p, i);
		else
			parent(p.fd);
	}
	for_the_forking(&childpid);
	if (childpid == 0 && i != 0)
		last_command(argv, envp, p, i);
	while (wait(&p.status) > 0)
		close(p.file[1]);
	return (0);
}
