/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:17 by lhima             #+#    #+#             */
/*   Updated: 2025/02/15 14:52:01 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "pipex.h"


void	child_do(int argc, char **argv, char **envp, int *fd)
{
	pid_t	childpid;
	int		i;

	i = -1;
	dup2(fd[1], 1);
	close(fd[1]);
	child(argv[2 + i], envp, fd);
	while (argc - 4 > ++i)
	{
		for_the_forking(&childpid);
		if (childpid == 0)
		{
			dup2(fd[1], 1);
			close(fd[1]);
			child(argv[2 + i], envp, fd);
		}
		dup2(fd[0], 0);
		close(fd[0]);
	}
	parent(fd);
	wait(NULL);
}

void	argc_check_and_fd(int argc, int *file, char **argv)
{
	if (argc != 5)
	{
		perror("error argc\n");
		exit(1);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}
*/

// funziona ma va corretto il codice
#include "pipex.h"

char    *find_command(char *argv,char **envp)
{
    int     i;
    char    **path;
    char    *command;    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            path = ft_split(envp[i] + 5, ':');
        i++;
    }
    i = 0;
    while (path[i])
    {
        command = ft_strjoin(ft_strjoin(path[i], "/"), argv);
        if (access(command, F_OK) == 0)
            return (command);
        i++;
    }
    return (NULL);
}

int	for_the_forking(pid_t *childpid)
{
	*childpid = fork();
	if (*childpid == -1)
	{
		perror("error fork\n");
		exit(1);
	}
	return (0);
}


int find_space(const char *s, int c)
{
    int i;    i = 0;
    c = (unsigned char)c;
    while (s[i] != '\0')
    {
        if (c == s[i])
            return (i);
        i ++ ;
    }
    if (c == s[i])
        return (i);
    return (ft_strlen(s));
} 

void    child(char  *argv,char  **envp, int fd[2])
{
    char    *command;

	dup2(fd[1], 1);
	close(fd[1]);
    command = find_command(ft_substr(argv, 0, find_space(argv, ' ')), envp);
    if(execve(command, ft_split(argv, ' '), envp) == -1)
    {
        perror("error execve\n");
        exit(1);
    }
}

void    parent(int fd[2])
{
    close(fd[1]);
    dup2(fd[0], 0);
}

void pipe_creation(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("error pipe\n");
		exit(1);
	}
}

void	argc_check_and_fd(int argc, int *file, char **argv)
{
	if (argc != 5)
	{
		perror("error argc\n");
		exit(1);
	}
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(file[0] == -1 || file[1] == -1)
	{
		perror("error file\n");
		exit(1);
	}
}
void	child_do(int argc, char **argv, char **envp, t_pipex *p)
{
	pid_t	childpid;
	int		i;

	i = 0;
	while(argc - 4 > i)
	{
		pipe_creation(p->fd);
		for_the_forking(&childpid);
		if(childpid == 0)
		{
			close(p->fd[0]);
			close(p->file[1]);
			child(argv[2 + i], envp, p->fd);
		}
		else
			parent(p->fd);
		wait(NULL);
		close(p->fd[0]);
		i++;
	}
}



int main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;
   // pid_t   childpid;
    pid_t   childpid2;

	argc_check_and_fd(argc, pipex.file, argv);
    dup2(pipex.file[0], 0);
	close(pipex.file[0]);
	//pipe_creation(pipex.fd);
	for_the_forking(&childpid2);
    if (childpid2 == 0)
    {
		child_do(argc, argv, envp, &pipex);
        dup2(pipex.file[1], 1);
		close(pipex.file[1]);
        execve(find_command(ft_substr(argv[argc - 2], 0, find_space(argv[argc - 2], ' ')), envp), ft_split(argv[argc - 2], ' '), envp);
    }
    else
    {
        waitpid(childpid2, NULL, 0);
        close(pipex.file[0]);
        close(pipex.file[1]);
    }
    return (0);
}
