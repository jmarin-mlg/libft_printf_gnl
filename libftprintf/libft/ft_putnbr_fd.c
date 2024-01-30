/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:17:59 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:29:43 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   n: The number to send.
**   fd: The file descriptor to write to.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int	divisor;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	divisor = 1;
	while (n / divisor > 9)
		divisor *= 10;
	while (divisor > 0)
	{
		ft_putchar_fd((n / divisor) + '0', fd);
		n %= divisor;
		divisor /= 10;
	}
	return ;
}
