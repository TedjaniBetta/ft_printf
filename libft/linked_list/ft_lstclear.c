/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:53:38 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/10 01:53:41 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*next;

	if (lst && del)
	{
		begin = *lst;
		while (begin != NULL)
		{
			next = begin->next;
			(*del)(begin->content);
			free(begin);
			begin = next;
		}
	}
	*lst = NULL;
}
