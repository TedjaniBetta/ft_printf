/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:25:03 by tebetta           #+#    #+#             */
/*   Updated: 2019/12/24 02:25:11 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_number_space(t_flags *flags, int nb_char)
{
	if (!flags || flags->width == -1)
		return (0);
	if (flags->width > nb_char)
		return (flags->width - nb_char);
	else
		return (0);
}
