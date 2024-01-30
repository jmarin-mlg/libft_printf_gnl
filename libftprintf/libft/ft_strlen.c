/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:49:08 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:40:12 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function computes the length of the string s. The function attempts to
** compute the length of s, but never scans beyond the first maxlen bytes of s.
**
** The function returns the number of characters that precede the terminating
** NUL character.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		++i;
	return (i);
}
