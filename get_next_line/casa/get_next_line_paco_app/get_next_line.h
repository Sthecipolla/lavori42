

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
// # include <bsd/string.h>
#include <fcntl.h>
#include <unistd.h>
// #include <linux/stat.h>
#include <sys/stat.h>
#include <stddef.h>

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(const char *c);
void *ft_calloc(size_t nmemb, size_t size);
int ft_strncmp(const char *s1, const char *s2);

#endif