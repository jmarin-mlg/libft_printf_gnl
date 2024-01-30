/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:44:35 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:18:32 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isalnum() function tests for any character for which isalpha(3) or
** isdigit(3) is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF. The isalnum() function returns zero if
** the character tests false and returns non-zero if the character tests true.
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
