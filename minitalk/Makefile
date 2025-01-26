# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 15:13:54 by nafarid           #+#    #+#              #
#    Updated: 2025/01/24 18:18:00 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources -------------------------------

# Files
SERVER = server
CLIENT = client
PRINTF = ft_printf
PRINTF_LIB = $(PRINTF)/libftprintf.a  

# ------------------------------ Constant strings ----------------------

CC =  cc
FLAGS = -Wall -Wextra -Werror 

# ------------------------------ Rules ---------------------------------

all:
	@cd ft_printf && $(MAKE) -s
	@$(CC) $(FLAGS) server.c $(PRINTF_LIB) -o $(SERVER)
	@$(CC) $(FLAGS) client.c $(PRINTF_LIB) -o $(CLIENT)
	@echo "Server And Client Are Ready!"

clean:
	@cd ft_printf && $(MAKE) -s clean
	
fclean: clean
	@cd ft_printf && $(MAKE) -s fclean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all
