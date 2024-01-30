/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:55:37 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 07:21:01 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The isascii() function tests for an ASCII character, which is any character
** between 0 and octal 0177 inclusive (Decimal 0 - 127).
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
