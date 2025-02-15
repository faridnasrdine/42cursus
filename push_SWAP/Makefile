# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 13:53:15 by nafarid           #+#    #+#              #
#    Updated: 2025/02/15 13:36:04 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = src/check_arranging.c src/check_cout.c src/check_error.c \
      src/check_duplicate.c src/free.c src/list_arg_check.c src/operations1.c \
      src/operations2.c src/operations.c src/print_error.c  src/push_swap.c \
	  src/check_args.c src/utils.c src/radix.c src/sort.c mini_libft/ft_split.c \
	  mini_libft/ft_atoi.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJS = ${SRC:.c=.o}
NAME = push_swap
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all:
	@$(CC) $(CFLAGS) ${SRC} -o $(NAME)

clean:
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}
re: fclean all
.PHONY: all clean fclean re
