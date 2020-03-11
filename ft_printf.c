/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:19:32 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 01:36:13 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fct_print(const char *format, t_printf *vars, va_list ap)
{
	t_flags		*flags;

	flags = get_flags(format, &(vars->index), ap);
	vars->type = get_type(format, vars->index);
	vars->arg = get_arg(ap, vars);
	ft_display(vars, flags);
	vars->index++;
	free(flags);
}

int				ft_printf(const char *format, ...)
{
	t_printf	vars;
	va_list		ap;

	vars.index = 0;
	vars.return_size = 0;
	va_start(ap, format);
	while (format[vars.index] != '\0')
	{
		if (format[vars.index] == '%')
		{
			vars.index++;
			fct_print(format, &vars, ap);
		}
		else
		{
			ft_putchar(format[vars.index]);
			vars.index++;
			vars.return_size++;
		}
	}
	va_end(ap);
	return (vars.return_size);
}
