/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:04:09 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:29:50 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function writes n zeroed bytes to the string s.
** If n is zero, does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, 0, n);
	return ;
}
