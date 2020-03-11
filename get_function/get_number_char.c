/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:20:00 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/18 05:51:34 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			get_numbers_char_hexa(t_printf *vars, t_flags *flags)
{
	int		nb_char;

	nb_char = 0;
	if (vars->type == 'p')
		nb_char = 2;
	if (flags->precision == -1)
		nb_char += ft_strlen(vars->arg);
	else if (flags->precision > ft_strlen(vars->arg))
		nb_char += flags->precision;
	else
		nb_char += ft_strlen(vars->arg);
	return (nb_char);
}

static int			get_numbers_char_int(t_printf *vars, t_flags *flags)
{
	size_t		nb_char;

	nb_char = 0;
	if (flags->precision == -1)
		nb_char = ft_strlen(vars->arg);
	else if (flags->precision >= ft_strlen(vars->arg))
	{
		nb_char = flags->precision;
		if (vars->arg[0] == '-')
			nb_char++;
	}
	else
		nb_char = ft_strlen(vars->arg);
	return (nb_char);
}

static int			get_numbers_char_str(t_printf *vars, t_flags *flags)
{
	if (flags->precision == -1)
		return (ft_strlen(vars->arg));
	else if (flags->precision == 0)
		return (0);
	else if (flags->precision >= ft_strlen(vars->arg))
		return (ft_strlen(vars->arg));
	else
		return (flags->precision);
}

int					get_number_char(t_printf *vars, t_flags *flags)
{
	int			nb_char_print;

	if (is_char(vars->type))
		return (1);
	if (is_str(vars->type))
		nb_char_print = get_numbers_char_str(vars, flags);
	else if (is_int(vars->type))
		nb_char_print = get_numbers_char_int(vars, flags);
	else if (is_hex(vars->type))
		nb_char_print = get_numbers_char_hexa(vars, flags);
	return (nb_char_print);
}
