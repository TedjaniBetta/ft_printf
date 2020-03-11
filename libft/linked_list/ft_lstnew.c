/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:21:10 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/09 21:56:30 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*bloc;

	if (!(bloc = malloc(sizeof(t_list))))
		return (NULL);
	bloc->content = content;
	bloc->next = NULL;
	return (bloc);
}
