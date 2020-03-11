/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebetta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:48:56 by tebetta           #+#    #+#             */
/*   Updated: 2020/01/03 20:42:10 by tebetta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_printf
{
	int			index;
	int			return_size;
	char		*arg;
	char		type;
}				t_printf;

typedef struct	s_flags
{
	char		flag;
	int			width;
	int			precision;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_display(t_printf *vars, t_flags *flags);
char			get_type(const char *format, int index);
char			*get_arg(va_list ap, t_printf *vars);
t_flags			*get_flags(const char *f, int *index, va_list ap);
int				get_number_char(t_printf *vars, t_flags *flags);
int				get_number_space(t_flags *flags, int nb_char);
void			display_str(t_printf *v, t_flags *f, int nb_char_p, int nb_spa);
void			display_int(t_printf *v, t_flags *f, int nb_char_p, int nb_spa);
void			display_c(t_printf *vars, t_flags *flags, int nb_spazero_print);
void			display_h(t_printf *v, t_flags *f, int nb_char_p, int nb_spa);
t_flags			*ft_flags(void);
char			get_flag(const char *format, int *index);
int				get_width(const char *format, int *index, char *flag);
int				get_precision(const char *format, int *index, t_flags *flags);
int				is_int(char type);
int				is_hex(char type);
int				is_char(char type);
int				is_str(char type);
#endif
