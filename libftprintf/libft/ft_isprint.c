/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:21:55 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:23:19 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isprint() function tests for any printing character, including
** space (` ').  The value of the argument must be representable as an unsigned
** char or the value of EOF. The isprint() function returns zero if the
** character tests false and returns non-zero if the character tests true.
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
