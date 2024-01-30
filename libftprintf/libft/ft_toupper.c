/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:24:33 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/24 19:04:30 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The toupper() function converts a lower-case letter to the corresponding
** upper-case letter.  The argument must be representable as an unsigned char or
** the value of EOF.
**
** Although the toupper() function uses the current locale, the toupper_l()
** function may be passed a locale directly. See xlocale(3) for more information
**
** If the argument is a lower-case letter, the toupper() function returns the
** corresponding upper-case letter if there is one; otherwise, the argument is
** returned unchanged.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
