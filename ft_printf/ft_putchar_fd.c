/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:36:07 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/30 06:22:18 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   c: The character to send.
**   fd: The file descriptor to write to.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
