/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 05:13:31 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/27 06:01:06 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function locates the first occurrence of c (converted to a char) in the
** string pointed to by s. The terminating null character is considered to be
** part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
**
** The functions ft_strchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/
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
