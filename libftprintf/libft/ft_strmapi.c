/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:38:04 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/30 07:13:23 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   s: The string to iterate.
**   f: The function to apply on each character.
**
** Returns the string created after the correct use of ’f’ on each character or
** NULL if memory reservation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
