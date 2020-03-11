/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 08:00:25 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/18 05:49:53 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		*ft_flags(void)
{
	t_flags	*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->flag = '\0';
	flags->width = -1;
	flags->precision = -1;
	return (flags);
}

char		get_flag(const char *format, int *index)
{
	char	flag;

	flag = format[*index];
	while (format[*index] == '0' || format[*index] == '-')
	{
		if (format[*index] == '-')
			flag = '-';
		(*index)++;
	}
	return (flag);
}

int			get_width(const char *format, int *index, char *flag)
{
	int		i;
	char	*width;
	int		size;

	i = (*index);
	size = 0;
	if (format[i] == '-')
	{
		*flag = '-';
		i++;
		(*index)++;
	}
	while (ft_isdigit(format[i++]))
		size++;
	if (!(width = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		width[i++] = format[(*index)++];
	width[i] = '\0';
	i = ft_atoi(width);
	free(width);
	return (i);
}

int			get_precision(const char *format, int *index, t_flags *flags)
{
	int		i;
	int		size;
	char	*precision;

	i = (*index);
	size = 0;
	if (format[i] == '-')
	{
		flags->flag = '-';
		i++;
		(*index)++;
	}
	while (ft_isdigit(format[i++]))
		size++;
	if (!(precision = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	i = 0;
	while (ft_isdigit(format[*index]))
		precision[i++] = format[(*index)++];
	precision[i] = '\0';
	i = ft_atoi(precision);
	free(precision);
	return (i);
}
