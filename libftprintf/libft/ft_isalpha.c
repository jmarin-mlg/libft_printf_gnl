/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:04:45 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:19:36 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isalpha() function tests for any character for which isupper(3) or
** islower(3) is true. The value of the argument must be representable as
** an unsigned char or the value of EOF. The isalpha() function returns zero
** if the character tests false and returns non-zero if the character tests true
*/
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
