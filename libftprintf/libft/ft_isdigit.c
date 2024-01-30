/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:57:05 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:22:23 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isdigit() function tests for a decimal digit character.
** Regardless of locale, this includes the following characters only
** The value of the argument must be representable as an unsigned char or the
** value of EOF. The isdigit() and isnumber() functions return zero if the
** character tests false and return non-zero if the character tests true.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
