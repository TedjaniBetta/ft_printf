/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:12:34 by tebetta           #+#    #+#             */
/*   Updated: 2019/10/31 14:28:41 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (dstsize <= d)
		return (s + dstsize);
	else
	{
		i = 0;
		while (d + i < dstsize - 1 && src[i] != '\0')
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
		return (d + s);
	}
}
