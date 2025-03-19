# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:42:37 by nafarid           #+#    #+#              #
#    Updated: 2025/03/06 00:01:34 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------Sources------------------------------------------------

SRC = src/check_file.c src/get_map.c src/parsing.c src/so_long.c \
      src/utlis.c get_next_line/get_next_line.c src/put_image.c src/print_text.c \
      get_next_line/get_next_line_utils.c src/flood_fill.c src/movement.c
OBJS = $(SRC:.c=.o)

#-------------------------Constant strings--------------------------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L/home/farid/Desktop/42cursus/so_long/minilibx-linux -lmlx_Linux -lX11 -lXext -lm
NAME = so_long
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

#----------------------Rules---------------------------------------------

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cd ${LIB_DIR} && ${MAKE} -s
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(LDFLAGS) -o $(NAME)
	
clean:
	@cd ${LIB_DIR} && $(MAKE) clean -s
	@rm -rf $(OBJS)

fclean: clean
	@cd ${LIB_DIR} && $(MAKE) fclean -s
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
