# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebetta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 17:10:45 by tebetta           #+#    #+#              #
#    Updated: 2019/11/18 16:06:35 by tebetta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAGS=-Wall -Wextra -Werror

CONVERT=Convert/ft_atoi.c \
		Convert/ft_itoa.c \
		Convert/ft_unsigned.c \
		Convert/ft_hexa.c \
		Convert/ft_str_uppercase.c \
		Convert/ft_hexap.c \
		Convert/ft_ltoa.c \
		

CHECKER=Checker/ft_isdigit.c\
		Checker/ft_isalnum.c \
		Checker/ft_isalpha.c \
		Checker/ft_isascii.c \
		Checker/ft_isdigit.c \
		Checker/ft_isprint.c \
		Checker/ft_tolower.c \
		Checker/ft_toupper.c \

MEMORY=memory/ft_bzero.c \
		memory/ft_memccpy.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memset.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_calloc.c \

LINKED_LIST=linked_list/ft_lstadd_front.c \
		linked_list/ft_lstsize.c \
		linked_list/ft_lstlast.c \
		linked_list/ft_lstadd_back.c \
		linked_list/ft_lstdelone.c \
		linked_list/ft_lstclear.c \
		linked_list/ft_lstiter.c \
		linked_list/ft_lstmap.c \
		linked_list/ft_lstnew.c \

STRING=String/ft_strchr.c \
		String/ft_strlcat.c \
		String/ft_strlcpy.c \
		String/ft_strlen.c \
		String/ft_strncmp.c \
		String/ft_strnstr.c \
		String/ft_strrchr.c \
		String/ft_strdup.c \
		String/ft_substr.c \
		String/ft_strjoin.c \
		String/ft_strtrim.c \
		String/ft_split.c \
		String/ft_strmapi.c \
		String/ft_strncpy.c \
		String/ft_putstr.c \
		String/ft_putnstr.c \
		String/ft_strcmp.c \

DISPLAY=Display/ft_putchar_fd.c \
		Display/ft_putstr_fd.c \
		Display/ft_putnbr_fd.c \
		Display/ft_putendl_fd.c \
		Display/ft_putchar.c \
		Display/ft_putnchar.c \

SRC= $(CONVERT) $(CHECKER) $(MEMORY) $(LINKED_LIST) $(STRING) $(DISPLAY)

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

.o: .c
	gcc $(FLAGS) -I./ -o $@ -c $<

clean:
	rm -f $(OBJ)

clean_b:
	rm -f $(OBJ_BON)

fclean: clean clean_b
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean clean_b fclean re
