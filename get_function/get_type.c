/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:11:15 by tebetta           #+#    #+#             */
/*   Updated: 2019/12/17 03:49:17 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		is_valide_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 's' || c == 'c' || c == '%')
		return (1);
	if (c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

char			get_type(const char *format, int index)
{
	char	type;

	if (is_valide_type(format[index]) == 1)
		type = format[index];
	else
		type = '\0';
	return (type);
}
