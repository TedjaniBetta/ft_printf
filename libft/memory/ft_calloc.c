/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:00:11 by tebetta           #+#    #+#             */
/*   Updated: 2019/10/28 21:10:31 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*str;

	if (nmemb * size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (!(str = (unsigned char *)malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
