# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 14:08:19 by rweiss            #+#    #+#              #
#    Updated: 2017/04/27 18:49:58 by rweiss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

RM = /bin/rm -f

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstiter.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strndup.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_lstadd.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstmap.c\
		ft_strnjoin.c\
		get_next_line.c\
		ft_clamp.c\
		ft_mix.c\
		ft_vec.c\
		ft_vec2.c\
		ft_vec3.c

OBJS = $(SRCS:.c=.o)

HEADER = ./libft.h

all : $(NAME)

$(NAME):
	@$(GCC) $(FLAGS) -c $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\e[31;1mlibft    \e[37;1m==>  \e[32;1mok\e[37m\n"

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
