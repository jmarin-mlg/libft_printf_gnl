/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:43:31 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/27 06:24:01 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   s1: The string that should be trimmed.
**   set: The characters to remove from the string.
**
** Returns the trimmed string or NULL if memory allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	if (start == end)
		return (ft_substr(s1, start, 0));
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		--end;
	return (ft_substr(s1, start, end - start));
}
