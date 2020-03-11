/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:48:37 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 01:55:25 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int		ft_unsigned(int n)
{
	long		max;

	max = 4294967296;
	if (n < 0)
		return (max + n);
	return (n);
}