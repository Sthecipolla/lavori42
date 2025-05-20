/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

static size_t	ft_count_words(char *s, char delimiter);
static int		ft_fill(char **w_v, char *s, char delimiter);
static int		ft_allocate_word(char **w_v, size_t position, size_t len_word);

/*
PARAMETERS
s: The string to be split.
c: The delimiter character.

EXTERNAL FUNCTIONS
malloc, free

DESCRIPTION
Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end
with a NULL pointer.

RETURN VALUE
The array of new strings resulting from the split.
NULL if the allocation fails.

EXPLANATION
At first, this function counts the number of words in s. Then it allocates
the memory for the array of words (words_vector). The last element of that
array is set to NULL. Then this function fills the array of words: if an
allocation error occurs, the ft_fill function returns FALSE and so also this
function returns FALSE; otherwise words_vector is returned.
*/
char	**ft_split(char const *s, char c)
{
	char	**words_vector;
	size_t	words;

	words = ft_count_words((char *) s, c);
	words_vector = (char **) malloc((words + 1) * sizeof(char *));
	if (words_vector == NULL)
		return (NULL);
	words_vector[words] = NULL;
	if (ft_fill(words_vector, (char *) s, c) == FALSE)
		return (NULL);
	return (words_vector);
}

/*
PARAMETERS
s: the string to split.
delimiter: the character that delimits words.

DESCRIPTION
This function counts the words in s.

RETURN VALUE
The number of words in s.

EXPLANATION
It starts by skipping every delimiter it finds; then, it increments the number
of words only if the character found is the first one of the word. After the
word ends, these last two sentences are repeated until the string s ends.
*/
static size_t	ft_count_words(char *s, char delimiter)
{
	size_t	words;
	int		inside_word;

	words = 0;
	while (*s != '\0')
	{
		inside_word = FALSE;
		while (*s == delimiter && *s != '\0')
			s++;
		while (*s != delimiter && *s != '\0')
		{
			if (inside_word == FALSE)
			{
				inside_word = TRUE;
				words++;
			}
			s++;
		}
	}
	return (words);
}

/*
PARAMETERS
w_v (words_vector): the array where to split the words.
s: the string to split into words_vector.
delimiter: the character that delimits words.

DESCRIPTION
This function fills the array of words w_v with the words from s.

RETURN VALUE
TRUE = 1 if every allocation succeded, FALSE = 0 if one allocation failed.

EXPLANATION
This function counts the letter of each word (its length, len_word) in s and
allocates the memory for that word in w_v[i_word] where i_word is the index
of the word. Then it copies the word from s to w_v[i_word] using ft_strlcpy:
the source is s - len_word because the former while loop brings the pointer
s to the first character after the world, so the pointer to the beginning of
the word is s - len_world. The number of characters to copy is len_word + 1
because an extra character for the null-terminating character is needed by
ft_strlcpy.
*/
static int	ft_fill(char **w_v, char *s, char delimiter)
{
	size_t	i_word;
	size_t	len_word;

	i_word = 0;
	while (*s != '\0')
	{
		len_word = 0;
		while (*s == delimiter && *s != '\0')
			s++;
		while (*s != delimiter && *s != '\0')
		{
			len_word++;
			s++;
		}
		if (len_word != 0)
		{
			if (ft_allocate_word(w_v, i_word, len_word) == FALSE)
				return (FALSE);
			ft_strlcpy(w_v[i_word], s - len_word, len_word + 1);
		}
		i_word++;
	}
	return (TRUE);
}

/*
PARAMETERS
w_v (words_vector): the array where to split the words.
position: the index in the array of the current word.
len_word: length of the current word.

DESCRIPTION
This function allocates the memory for each word in the array of words, and
it frees everything if one allocation fails.

RETURN VALUE
TRUE = 1 if the allocation succeded, FALSE = 0 if the allocation failed.

EXPLANATION
This function allocates the memory for the pointer words_vector[position]
(w_v[position]) using malloc(3), that is the word of index position.
It allocates a number of bytes equivalent to the length of the word
(len_word) + 1 for the null-terminating byte.
If that allocation fails, it frees all the previous allocations, so the words
of indexes from 0 to position - 1 and the array of words words_vector (w_v).
*/
static int	ft_allocate_word(char **w_v, size_t position, size_t len_word)
{
	size_t	i;

	i = 0;
	w_v[position] = (char *) malloc((len_word + 1) * sizeof(char));
	if (w_v[position] == NULL)
	{
		while (i < position)
		{
			free(w_v[i]);
			i++;
		}
		free(w_v);
		return (FALSE);
	}
	return (TRUE);
}
