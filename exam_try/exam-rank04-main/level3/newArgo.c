#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
// #include <malloc.h> // change this to <stdlib.h>
#include <stdlib.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

void	free_json(json j);
int		argo(json *dst, FILE *stream);

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}

int	ft_strlen(char *string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_add_char(char *string, char c)
{
	int i = 0;
	char *new_string;
	
	new_string = calloc(ft_strlen(string) + 2, 1);
	while (string[i] != '\0')
	{
		new_string[i] = string[i];
		i++;	
	}
	new_string[i] = c;
	free(string);
	return (new_string);
}

int	parse_string(json *dst, FILE *stream)
{
	dst->type = STRING;
	char c;
	char *string = calloc(1, 1);

	if (expect(stream, '"') == 0)
		return (-1);
	c = getc(stream);
	while (c != '\0' && c != EOF)
	{
		if (c == '\\') {
			// Handle escape
			char next = getc(stream);
			if (next == '"' || next == '\\') {
				string = ft_add_char(string, c);
				string = ft_add_char(string, next);
				c = getc(stream);
				continue;
			} else if (next == EOF) {
				unexpected(stream);
				free(string);
				return -1;
			} else 
			{
				// Invalid escape, treat as unexpected token
				unexpected(stream);
				free(string);
				return -1;
			}
		}
		if (c == '"')
			break;
		string = ft_add_char(string, c);
		c = getc(stream);
		if(peek(stream) == '"')
		{
			string = ft_add_char(string, c);
			break;
		}
	}
	if (expect(stream, '"') == 0)
		return (free(string), 0);
	dst->string = string;
	return (1);
}

int parse_num(json *dst,FILE *stream)
{
	int n;
	if (fscanf(stream, "%d", &n) == 1)
	{
		dst->type = INTEGER;
		dst->integer = n;
		return (1);
	}
	unexpected(stream);
	return (-1);
}

void free_pair(pair *pa, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        free(pa[i].key);
        free_json(pa[i].value);
    }
    free(pa);
}

int parse_map(json *dts, FILE *stream)
{
	pair		*array;
	size_t		size = 0;
	json		key;

	if (!expect(stream, '{'))
        return 0;
	array = NULL;
	while(!accept(stream, '}'))
	{
		array = realloc(array , sizeof(pair) * (1 + size));
		if (!parse_string(&key, stream))
        	return (-1);
		if (!expect(stream, ':'))
				return (-1);
		if (!argo(&array[size].value, stream))
        	return (-1);
		array[size].key = key.string;
		size++;
		if (!accept(stream, ',') && peek(stream) != '}')
		{
			unexpected(stream);
			free_pair(array, size);
			return (-1);
		}
		if (accept(stream, ','))
				continue;
		if (peek(stream) == '}')
			continue;
		if (peek(stream) == EOF) {
			unexpected(stream);
			free_pair(array, size);
			return -1;
		}
	}
	dts->type = MAP;
	dts->map.size = size;
	dts->map.data = array;
	return (1);
}
// Allowed functions: getc,
// ungetc, printf, malloc,
// calloc, realloc, free, 
// isdigit, fscanf, write

int	argo(json *dst, FILE *stream)
{
	char c;

	c = peek(stream);
	if (c == '"')
		return (parse_string(dst, stream));
	else if (isdigit(c) || c == '-')
		return(parse_num(dst, stream));
	if(c >= '{')
		return(parse_map(dst, stream));
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return (1);
	}
	serialize(file);
	printf("\n");
}
