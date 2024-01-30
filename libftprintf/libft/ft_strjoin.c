/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:09:57 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:29:54 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   s1: The first string.
**   s2: The string to add to ’s1’.
**
** Returns the new string or NULL if memory allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *) ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	return (res);
}
