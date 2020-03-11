/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:28:35 by tebetta           #+#    #+#             */
/*   Updated: 2019/12/23 04:29:02 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	display_c(t_printf *vars, t_flags *flags, int nb_spazero_print)
{
	if (flags->flag == '-')
	{
		ft_putchar(vars->arg[0]);
		ft_putnchar(' ', nb_spazero_print);
	}
	else if (flags->flag == '0')
	{
		ft_putnchar('0', nb_spazero_print);
		ft_putchar(vars->arg[0]);
	}
	else
	{
		ft_putnchar(' ', nb_spazero_print);
		ft_putchar(vars->arg[0]);
	}
}
