/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:29:56 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/24 19:03:23 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The tolower() function converts an upper-case letter to the corresponding
** lower-case letter.  The argument must be representable as an unsigned char or
** the value of EOF.
**
** Although the tolower() function uses the current locale, the tolower_l()
** function may be passed a locale directly. See xlocale(3) for more information
**
** If the argument is an upper-case letter, the tolower() function returns the
** corresponding lower-case letter if there is one; otherwise, the argument is
** returned unchanged.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
