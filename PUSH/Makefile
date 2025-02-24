# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 13:53:15 by nafarid           #+#    #+#              #
#    Updated: 2025/02/18 17:02:29 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------Sources------------------------------------------------
SRC = 	check_arranging.c check_error.c check_duplicate.c free.c \
		list_arg_check.c operations2.c operations.c push_swap.c \
	  	check_args.c utils.c radix.c sort.c ft_split.c ft_atoi.c \

#-------------------------Constant strings--------------------------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJS = ${SRC:.c=.o}
NAME = push_swap

#----------------------Rules---------------------------------------------
%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) ${SRC} -o $(NAME)

clean:
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}
re: fclean all
.PHONY: all clean fclean re