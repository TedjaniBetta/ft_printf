/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:11:11 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/18 05:52:06 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		fct_precision(const char *f, int *inde, t_flags *fl, va_list ap)
{
	if (f[*inde] == '.' && (ft_isdigit(f[++(*inde)]) || f[*inde] == '-'))
		fl->precision = get_precision(f, inde, fl);
	else if (f[*inde - 1] == '.' && f[(*inde)] == '*')
	{
		fl->precision = va_arg(ap, int);
		if (fl->precision < 0)
			fl->precision = -1;
		(*inde)++;
	}
	else if (f[*inde - 1] == '.')
		fl->precision = 0;
}

t_flags			*get_flags(const char *f, int *index, va_list ap)
{
	t_flags		*fl;

	fl = ft_flags();
	if (f[*index] == '-' || f[*index] == '0')
		fl->flag = get_flag(f, index);
	if (ft_isdigit(f[*index]) || f[*index] == '*')
	{
		if (f[*index] == '*')
		{
			fl->width = va_arg(ap, int);
			if (fl->width < 0)
			{
				fl->width *= -1;
				fl->flag = '-';
			}
			(*index)++;
		}
		else if (ft_isdigit(f[*index]) || f[*index] == -1)
			fl->width = get_width(f, index, &(fl->flag));
	}
	fct_precision(f, index, fl, ap);
	return (fl);
}
