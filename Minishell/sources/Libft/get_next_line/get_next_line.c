/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:31:39 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/17 09:42:07 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
PARAMETERS
fd:	file descriptor to read from

EXTERNAL FUNCTIONS
read, malloc, free

DESCRIPTION
This function returns a line read from a file descriptor. It can manage
multiple file descriptors a the same time.

RETURN VALUE
Read line:	correct behavior
NULL:		there is nothing else to read, or an error occurred

EXPLANATION
This function reads the file descripted by fd, by reading BUFFER_SIZE bytes at
a time. It exploits the functionalities of the read function, which every time
it is called it restarts reading from where it stopped the last time.
left_chars is a static variable which contains an array of strings, and the
i-th string will contain the characters read in the previous call to this
function with fd = i and that are beyond the returned line.
The first if is a check about the following things:
 - 	fd < 0: this means the file descriptor is invalid
 - 	BUFFER_SIZE <= 0: we will read BUFFER_SIZE characters at a time, so we
	can't read 0 or less characters.
Another test I could have added is:
 -	read(fd, NULL, 0) < 0: this check lets us see if the file exists and that
 	it has some content to read from, or if that the file is readable (maybe
	the file descriptor is more than 0, but it was open in 'modify only', and
	that means we can't read it).
I didn't add it beacause the subject of this project explicitly says that I
can only use read with BUFFER_SIZE bytes read.
If one of this checks is true, the function frees left_chars if necessary and
returns NULL.
If none of the checks is true, a string buf of length BUFFER_SIZE is alloc'd
to contain the read characters. The function read_line then reads the file
until a \n or the eof is found. The function set_line truncates the line at
the \n or the eof and puts the remaining characters in the left_chars static
variable. Then the line is returnes.
*/
char	*get_next_line(int fd)
{
	static char	*left_chars[MAX_FD];
	char		*buf;
	char		*tmp_line;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (fd >= 0 && left_chars[fd] != NULL)
			free(left_chars[fd]);
		return (NULL);
	}
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	tmp_line = read_line(fd, &left_chars[fd], buf);
	free (buf);
	if (tmp_line == NULL)
		return (NULL);
	line = set_line(tmp_line, &left_chars[fd]);
	free(tmp_line);
	return (line);
}

/*
PARAMETERS
fd:			file descriptor to read from
left_chars:	pointer to the static variable left_chars
buf: 		buffer where to put the read characters

EXTERNAL FUNCTIONS
read, malloc, free

DESCRIPTION
This function reads from the file descripted by fd until a \n or eof is found.

RETURN VALUE
Read chars:	correct behaviour
NULL:		there is nothing else to read, or an error occurred

EXPLANATION
This function reads the file descripted by fd, by reading BUFFER_SIZE bytes at
a time. It starts by managing the left characters from previous runs by using
the function manage_left_chars. Then it enters a while loop which continues
until a \n is found in the read characters or the eof is reached.
BUFFER_SIZE characters are read into buf. If the number of bytes read is -1,
then an error occuered and NULL is returned (maybe the file was open in write
only mode). If the number of bytes read is 0, then the eof is reached and the
loop breaks. The buffer is nul-terminated.
The buffer is joined with the precedent reads contained in tmp_line, and then
tmp_line is assigned to the new joined string. When the function exits from
the while loop, it returns tmp_line.
*/
char	*read_line(int fd, char **left_chars, char *buf)
{
	char	*tmp;
	char	*tmp_line;
	long	bytes_read;

	bytes_read = 1;
	tmp_line = manage_left_chars(left_chars);
	while (ft_strchr(tmp_line, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_line);
			if (*left_chars != NULL)
				free(*left_chars);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(tmp_line, buf);
		free(tmp_line);
		tmp_line = tmp;
	}
	return (tmp_line);
}

/*
PARAMETERS
left_chars:	pointer to the static variable left_chars

EXTERNAL FUNCTIONS
read, malloc, free

DESCRIPTION
This function manages the left characters from the previous runs.

RETURN VALUE
An empty line if there are not any left characters.
A copy of the string left from the previous run otherwise.

EXPLANATION
left_chars is a static variable, so it is automatically initialized to 0 (so
NULL). The first time get_next_line is called, tmp_line is duplicated from an
empty string, while the next times is duplicated from the previous left_chars.
*/
char	*manage_left_chars(char **left_chars)
{
	char	*tmp_line;

	if (*left_chars == NULL)
		tmp_line = ft_strdup("\0");
	else
	{
		tmp_line = ft_strdup(*left_chars);
		free(*left_chars);
		*left_chars = NULL;
	}
	return (tmp_line);
}

/*
PARAMETERS
tmp_line:	the line read which has to be truncated at the \n
left_chars:	pointer to the static variable left_chars

EXTERNAL FUNCTIONS
read, malloc, free

DESCRIPTION
This function truncates the line at the \n and puts the remaining characters
into the left_chars static variable.

RETURN VALUE
The line, or NULL if tmp_line is empty or an error occurred

EXPLANATION
This function starts by measuring the length i of tmp_line until the first \n
or the end of the line if there is no \n. If the length is 0, so tmp_line is
empty, then it returns NULL (if the function get_next_line is called again
after the eof, then the line returned is NULL as indicated in the subject).
The line is obtained as a substring of tmp_line of lenght i plus 1 for the \n
character. left_chars is obtained as a substring of tmp_line containing the
remaining characters; if there are no remaining characters in tmp_line, then
the function ft_substr allocates the left_chars pointer and sets its value to
'\0', so in this case left_chars is an empty string.
*/
char	*set_line(char *tmp_line, char **left_chars)
{
	char	*line;
	size_t	i;

	i = 0;
	while (tmp_line[i] != '\n' && tmp_line[i] != '\0')
		i++;
	if (i == 0 && tmp_line[i] == '\0')
		return (NULL);
	line = ft_substr(tmp_line, 0, i + 1);
	if (line == NULL)
	{
		if (left_chars != NULL)
			free(left_chars);
		return (NULL);
	}
	*left_chars = ft_substr(tmp_line, i + 1, ft_strlen(tmp_line) - i - 1);
	if (*left_chars == NULL)
		return (NULL);
	return (line);
}
