/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:08:49 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/01 14:42:12 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s[len] == c)
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len - 1] == c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (0);
}
