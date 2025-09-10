#include <unistd.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int id;
	int pipes[2];
	
	id = fork();
	pipe(pipes);
	if (id == 0)
	{
		if(type == 'r')
		{
			close(pipes[1]);
			dup2(pipes[0], 0);
			close(pipes[0]);
		}
		else if(type == 'w')
		{
			close(pipes[0]);
			dup2(pipes[1], 1);
			close(pipes[1]);
		}
		execvp(file, argv);
	}
	else
	{
		if(type == 'r')
		{
			close(pipes[1]);
			dup2(pipes[0], 0);
			close(pipes[0]);
		}
		else if(type == 'w')
		{
			close(pipes[0]);
			dup2(pipes[1], 1);
			close(pipes[1]);
		}
	}
	
}

int	main() {
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	char	*line;
	while ((line = get_next_line(fd)))
		ft_putstr(line);
}