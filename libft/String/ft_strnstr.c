/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:15 by tebetta           #+#    #+#             */
/*   Updated: 2019/10/28 21:37:47 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = ft_strlen(needle);
	if (*s2 == '\0')
		return (s1);
	while (*s1 != '\0' && len >= i)
	{
		if (ft_strncmp(s1, s2, i) == 0)
			return (s1);
		s1++;
		len--;
	}
	return (NULL);
}
