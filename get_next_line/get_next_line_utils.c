/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 06:08:23 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/10/30 06:57:32 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calculates the length of a null-terminated string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		++i;
	return (i);
}

// Concatenates two strings and returns the result.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (ft_free_memory(&s1));
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	ft_free_memory(&s1);
	return (res);
}

// Returns a pointer to the first occurrence of a character in a string.
char	*ft_strchr(const char *s, int c)
{
	char	searched;
	int		i;

	searched = (unsigned char) c;
	i = 0;
	while (s[i])
		if (s[i++] == searched)
			return ((char *) s + i - 1);
	if (s[i] == searched)
		return ((char *) s + i);
	return (NULL);
}

// Extracts a substring from a string.
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		res = (char *) malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

// Frees memory allocated for a string pointer and sets it to NULL.
char	*ft_free_memory(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
