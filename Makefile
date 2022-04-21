# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rverscho <rverscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/02 19:12:32 by rverscho       #+#    #+#                 #
#    Updated: 2020/01/19 16:46:16 by rverscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = empty_flags.c fill_struct_to_write_hex.c fill_struct_to_write_int.c \
	fill_struct_to_write_str.c functions.c make_char.c make_numbers.c \
	ft_printf.c the_mother.c string_check.c \
	set_1_0_for_int.c set_1_0_for_str.c utils.c utils2.c utils3.c get_len.c

BONUS = empty_flags.c fill_struct_to_write_hex.c fill_struct_to_write_int.c \
	fill_struct_to_write_str.c functions.c make_char.c make_numbers.c \
	ft_printf.c the_mother.c string_check.c \
	set_1_0_for_int.c set_1_0_for_str.c utils.c utils2.c utils3.c get_len.c

O_FILES := $(SRC:.c=.o)
BO_FILES := $(BONUS:.c=.o)
CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

bonus: $(NAME) $(BO_FILES)
	ar rc $(NAME) $(BO_FILES)

%.o: %.c
	$(CC) -c $? -o $@

clean:
	/bin/rm -f $(O_FILES) $(BO_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
