/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 07:34:44 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/27 06:37:00 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   s: The string from which to create the substring.
**   start: The index of the character in ’s’ from which to start the substring.
**   len: The maximum length of the substring.
**
** Returns the resulting substring, or NULL if memory allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_calloc(1, sizeof(char)));
	if ((size - start) < len)
		len = size - start;
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		++i;
	}
	return (res);
}
