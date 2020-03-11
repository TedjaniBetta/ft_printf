/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:57:03 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/10 00:37:44 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *end;

	end = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (end->next != NULL)
			end = end->next;
		end->next = new;
	}
}
