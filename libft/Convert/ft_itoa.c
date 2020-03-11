/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:10:24 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/10 22:32:53 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int		get_size_n(unsigned int n)
{
	unsigned int		size;

	size = 0;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size + 1);
}

char					*ft_itoa(int n)
{
	unsigned int		size;
	unsigned int		nb;
	int					i;
	char				*str;

	nb = (n < 0) ? (unsigned int)(n * -1) : (unsigned int)n;
	size = (n < 0) ? get_size_n(nb) + 1 : get_size_n(nb);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = size - 1;
	str[size] = '\0';
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = (nb % 10) + '0';
	return (str);
}
