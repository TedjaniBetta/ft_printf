/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:46:31 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 01:54:17 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		get_size(long n)
{
	int			size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char			*ft_ltoa(long n)
{
	int			i;
	int			size;
	char		*str;

	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	size = get_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size - 1;
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n % 10 + '0';
	return (str);
}
