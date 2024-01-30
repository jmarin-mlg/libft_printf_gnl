/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:52:01 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/30 06:22:28 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   s: The string to send.
**   fd: The file descriptor to write to.
*/
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return ;
}
