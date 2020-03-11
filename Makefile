# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebetta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 11:50:23 by tebetta           #+#    #+#              #
#    Updated: 2020/01/14 02:22:26 by tebetta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

FLAGS=-Wall -Wextra -Werror

SRC=ft_printf.c \
	get_function/get_type.c \
	get_function/get_arg.c \
	get_function/get_flags.c \
	get_function/get_number_space.c \
	get_function/get_number_char.c \
	get_function/flag_norme.c \
	display_function/ft_display.c \
	display_function/display_str.c \
	display_function/display_int.c \
	display_function/display_c.c \
	display_function/display_h.c \
	


OBJ= $(SRC:.c=.o)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $^
	ranlib $(NAME)
.o: .c
	gcc $(FLAGS) -o $@ -c $<
clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re
