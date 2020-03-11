/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:03:30 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/10 02:03:31 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*debut;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	debut = new;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&debut, (*del));
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (debut);
}
