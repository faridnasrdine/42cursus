# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 18:58:48 by nafarid           #+#    #+#              #
#    Updated: 2025/04/20 10:30:11 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/parsing.c src/init.c src/utils.c src/philo.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -pthread 
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re