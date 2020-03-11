/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:09:10 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 02:10:35 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	compt_mot(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	compt_let(char const *str, size_t index, char c)
{
	size_t		let;

	let = 0;
	while (str[index] != '\0' && str[index] != c)
	{
		index++;
		let++;
	}
	return (let);
}

static	char	**free_tab(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char *) * (compt_mot(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && j < compt_mot(s, c))
		{
			if (!((tab[j++] = ft_substr(s, i, compt_let(s, i, c)))))
				return (free_tab(tab, j));
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	tab[j] = 0;
	return (tab);
}
