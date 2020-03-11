/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:13:47 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/18 05:48:15 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			is_int(char type)
{
	if (type == 'i' || type == 'd' || type == 'u')
		return (1);
	return (0);
}

int			is_hex(char type)
{
	if (type == 'x' || type == 'X' || type == 'p')
		return (1);
	return (0);
}

int			is_char(char type)
{
	if (type == 'c' || type == '%')
		return (1);
	return (0);
}

int			is_str(char type)
{
	if (type == 's')
		return (1);
	return (0);
}

void		ft_display(t_printf *vars, t_flags *flags)
{
	int		nb_char_print;
	int		nb_spazero_print;

	nb_char_print = get_number_char(vars, flags);
	nb_spazero_print = get_number_space(flags, nb_char_print);
	vars->return_size += nb_char_print + nb_spazero_print;
	if (is_int(vars->type))
		display_int(vars, flags, nb_char_print, nb_spazero_print);
	else if (is_str(vars->type))
		display_str(vars, flags, nb_char_print, nb_spazero_print);
	else if (is_char(vars->type))
		display_c(vars, flags, nb_spazero_print);
	else if (is_hex(vars->type))
		display_h(vars, flags, nb_char_print, nb_spazero_print);
}
