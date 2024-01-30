/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:36:35 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/27 06:50:09 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   lst: The address of a pointer to a node.
**   del: A function pointer used to remove the content of a node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	return ;
}
