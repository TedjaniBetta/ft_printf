/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:43:19 by tebetta           #+#    #+#             */
/*   Updated: 2019/11/01 20:56:56 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + len1] = s2[i];
		i++;
	}
	str[i + len1] = '\0';
	return (str);
}
