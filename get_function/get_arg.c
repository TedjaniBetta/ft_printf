/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:11:05 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 01:31:06 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_char(char type, va_list ap)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (type == '%')
		str[0] = '%';
	else
		str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}

char		*get_arg(va_list ap, t_printf *vars)
{
	char		*arg;

	if (vars->type == 'd' || vars->type == 'i')
		arg = ft_itoa(va_arg(ap, int));
	else if (vars->type == 's')
	{
		arg = va_arg(ap, char *);
		if (arg == NULL)
			arg = ft_strdup("(null)");
	}
	else if (vars->type == 'u')
		arg = ft_ltoa(ft_unsigned(va_arg(ap, int)));
	else if (vars->type == 'c' || vars->type == '%')
		arg = get_char(vars->type, ap);
	else if (vars->type == 'p')
		arg = ft_hexap((long)va_arg(ap, void *));
	else if (vars->type == 'x' || vars->type == 'X')
	{
		arg = ft_hexa(va_arg(ap, int));
		arg = (vars->type == 'X') ? ft_str_uppercase(arg) : arg;
	}
	else
		vars->index++;
	return (arg);
}
