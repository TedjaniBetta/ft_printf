/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 06:04:39 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/18 05:49:15 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	ft_puthex(t_printf *vars, t_flags *flags, int nb_char)
{
	int i;
	int nb_zero;

	i = 0;
	if (vars->type == 'p')
	{
		ft_putstr("0x");
		nb_char -= 2;
	}
	nb_zero = nb_char - ft_strlen(vars->arg);
	if (nb_zero > 0)
		ft_putnchar('0', nb_zero);
	if (ft_strcmp(vars->arg, "0") == 0 && flags->precision == 0)
	{
		if (flags->width == -1 || flags->width == 0)
			vars->return_size--;
		else
			ft_putchar(' ');
	}
	else
		ft_putstr(&(vars->arg[i]));
}

void		display_h(t_printf *vars, t_flags *fl, int nb_char_p, int nb_spa)
{
	if (fl->flag == '-')
	{
		ft_puthex(vars, fl, nb_char_p);
		ft_putnchar(' ', nb_spa);
	}
	else if (fl->flag == '0')
	{
		if (nb_spa > 0 && fl->precision == -1)
			ft_puthex(vars, fl, nb_spa + nb_char_p);
		else
		{
			ft_putnchar(' ', nb_spa);
			ft_puthex(vars, fl, nb_char_p);
		}
	}
	else
	{
		ft_putnchar(' ', nb_spa);
		ft_puthex(vars, fl, nb_char_p);
	}
}
