# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:37:54 by nafarid           #+#    #+#              #
#    Updated: 2024/11/10 15:49:51 by nafarid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
          ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
          ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
          ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
          ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		  ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		  ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
		  ft_substr.c ft_striteri.c
 

OBJS = ${SRCS:.c=.o}

LIB = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${LIB}: ${OBJS}
	ar -rc ${LIB} ${OBJS}

all: ${LIB}

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: all clean fclean re
