/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:11:55 by tebetta           #+#    #+#             */
/*   Updated: 2019/12/24 02:16:02 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	display_str(t_printf *va, t_flags *f, int nb_char_p, int nb_spa)
{
	if (f->flag == '-')
	{
		ft_putnstr(va->arg, nb_char_p);
		ft_putnchar(' ', nb_spa);
	}
	else if (f->flag == '0')
	{
		ft_putnchar('0', nb_spa);
		ft_putnstr(va->arg, nb_char_p);
	}
	else
	{
		ft_putnchar(' ', nb_spa);
		ft_putnstr(va->arg, nb_char_p);
	}
}
