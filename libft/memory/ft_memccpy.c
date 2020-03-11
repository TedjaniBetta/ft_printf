/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:23:26 by tebetta           #+#    #+#             */
/*   Updated: 2019/10/28 21:14:53 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			dst[i] = src[i];
			i++;
			return (dst + i);
		}
		dst[i] = src[i];
		i++;
	}
	return (NULL);
}
