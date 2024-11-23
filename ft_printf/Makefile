# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 14:09:34 by nafarid           #+#    #+#              #
#    Updated: 2024/11/23 11:44:35 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c print_hex.c print_scp.c \
      print_int.c  print_unsigned_int.c \
      print_pointer.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY : all clean fclean re
