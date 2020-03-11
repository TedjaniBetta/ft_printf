/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 01:50:40 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/06 03:05:39 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int				get_size_n(unsigned long n)
{
	int					size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static unsigned long	convert_n_to_p(long n)
{
	unsigned long		max;

	max = ULONG_MAX;
	return (max + n + 1);
}

char					*ft_hexap(long nb)
{
	char				*base;
	char				*str;
	int					i;
	int					size;
	unsigned long		n;

	base = ft_strdup("0123456789abcdef");
	if (nb == 0)
		return ("0");
	if (nb < 0)
		n = convert_n_to_p(nb);
	else
		n = nb;
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
