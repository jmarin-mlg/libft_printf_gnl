/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:21:57 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:29:05 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function writes len bytes of value c (converted to an unsigned char) to
** the string b.
**
** The function returns its first argument.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*((unsigned char *) b + i++) = c;
	return (b);
}
