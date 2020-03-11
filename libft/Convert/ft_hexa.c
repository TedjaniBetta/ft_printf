/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:21:38 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/06 03:02:15 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		get_size_n(long n)
{
	int		size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static long		convert_n_to_p(long n)
{
	unsigned long	max;

	max = 4294967296;
	return (max + n);
}

char			*ft_hexa(long n)
{
	char	*str;
	char	*base;
	int		size;
	int		i;

	base = ft_strdup("0123456789abcdef");
	if (n == 0)
		return ("0");
	if (n < 0)
		n = convert_n_to_p(n);
	size = get_size_n(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	i = size - 1;
	while (n != 0)
	{
		str[i--] = base[n % 16];
		n /= 16;
	}
	free(base);
	return (str);
}
