/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:34:51 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:10:00 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** count_words: Count the number of words in a string delimited by a specified
** character.
**
** Parameters:
**   s: The input string.
**   c: Delimiting character.
**
** Returns:
**   The number of words in the string.
*/
static int	count_words(const char *s, char c)
{
	int	n_words;

	n_words = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			++n_words;
			while (*s && *s != c)
				++s;
		}
	}
	return (n_words);
}

/*
** save_word: Extract and save a word from a string into a newly allocated
** string.
**
** Parameters:
**   s: The input string.
**   start: The starting index of the word.
**   end: The ending index of the word.
**
** Returns:
**   A pointer to the newly allocated string containing the word, or NULL if
**   memory allocation fails.
*/
static char	*save_word(const char *s, int start, int end)
{
	char	*res;
	int		i;

	res = (char *) ft_calloc((end - start + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

/*
** free_memory: Free the memory allocated for an array of strings and set the
** array pointer to NULL.
**
** Parameters:
**   split: The array of strings to be freed.
**   index: The last index of the array to be freed.
**
** Returns:
**   Always returns NULL (useful for concise error handling).
*/
static void	*free_memory(char **split, int index)
{
	while (index-- > 0)
		free(split[index]);
	free(split);
	split = NULL;
	return (NULL);
}

/*
** Parameters:
**   s: The string to separate.
**   c: Delimiting character.
**
** Returns the array of new strings resulting from the split or NULL if memory
** allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	t_split	t;

	t.split = (char **) ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!s || !t.split)
		return (NULL);
	t.len = ft_strlen(s);
	t.i_st = 0;
	t.i_sp = 0;
	t.i_wo = -1;
	while (s[t.i_st])
	{
		while (s[t.i_st] == c)
			t.i_st++;
		if (s[t.i_st])
		{
			t.i_wo = t.i_st;
			while (s[t.i_st] && s[t.i_st] != c)
				t.i_st++;
			t.split[t.i_sp++] = save_word(s, t.i_wo, t.i_st);
			if (!t.split[t.i_sp - 1])
				return (free_memory(t.split, t.i_sp - 1));
		}
	}
	return (t.split);
}
