/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:09:39 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/06 10:25:30 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters:
**   lst: A pointer to a node.
**   f: The address of a pointer to a used function in iterating through each
**   item in the list.
**   del: A function pointer used to remove the content of a node, if necessary.
**
** Returns the new list or NULL if memory allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	res = NULL;
	while (lst)
	{
		aux = (t_list *) malloc(sizeof(t_list));
		if (!aux)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		aux->content = f(lst->content);
		aux->next = NULL;
		ft_lstadd_back(&res, aux);
		lst = lst->next;
	}
	return (res);
}
