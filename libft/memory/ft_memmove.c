/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:54 by tebetta           #+#    #+#             */
/*   Updated: 2019/10/14 19:04:29 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s[i] < d[i])
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (d);
}
