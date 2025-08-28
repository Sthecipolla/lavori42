#include <unistd.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
    int	std_in_and_out;
    
    int id;
    int fd_pipe[2];
    id = fork();
    pipe(fd_pipe);
    if (id = 0)
    {

    }

    
}

int	main()
{
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	char	*line;
	while ((line = get_next_line(fd)))
		ft_putstr(line);
}