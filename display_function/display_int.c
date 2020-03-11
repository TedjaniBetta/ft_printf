/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:44:35 by tebetta           #+#    #+#             */
/*   Updated: 2019/12/24 02:11:37 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_putint(t_printf *vars, t_flags *flags, int nb_pre)
{
	int		nb_zero;
	int		i;

	i = 0;
	if (vars->arg[i] == '-')
	{
		ft_putchar('-');
		i++;
		nb_pre--;
	}
	nb_zero = nb_pre - ft_strlen(&(vars->arg[i]));
	if (nb_zero > 0)
		ft_putnchar('0', nb_zero);
	if (ft_atoi(vars->arg) == 0 && flags->precision == 0)
	{
		if (flags->width == -1 || flags->width == 0)
			vars->return_size--;
		else
			ft_putchar(' ');
	}
	else
		ft_putstr(&(vars->arg[i]));
}

void			display_int(t_printf *va, t_flags *f, int nb_char_p, int nb_spa)
{
	if (f->flag == '-')
	{
		ft_putint(va, f, nb_char_p);
		ft_putnchar(' ', nb_spa);
	}
	else if (f->flag == '0')
	{
		if (nb_spa > 0 && f->precision == -1)
			ft_putint(va, f, nb_spa + nb_char_p);
		else
		{
			ft_putnchar(' ', nb_spa);
			ft_putint(va, f, nb_char_p);
		}
	}
	else
	{
		ft_putnchar(' ', nb_spa);
		ft_putint(va, f, nb_char_p);
	}
}
