/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:48:30 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/09 20:13:29 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_atoi(const char *str)
{
	long int		i;
	long int		neg;
	long int		stock;

	i = 0;
	neg = 0;
	stock = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		stock = (stock * 10) + (str[i] - 48);
		i++;
	}
	if (neg > 0)
		return (-stock);
	return (stock);
}
