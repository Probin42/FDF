# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rweiss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 12:08:33 by rweiss            #+#    #+#              #
#    Updated: 2017/04/27 18:49:45 by rweiss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft
I_LIBFT = -Ilibft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRC =	mainparser.c \
	 	draw.c \
	 	mlxfuncts.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft ./libmlx.a -framework OpenGL -framework AppKit
	@printf "\e[33;1mproject  \e[37;1m==>  \e[32;1mready\n"

.PHONY: clean fclean

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
