# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by jereligi          #+#    #+#              #
#    Updated: 2019/12/09 17:44:26 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

PATH = ./srcs/

SRCS =	Cub3d.c \
		ft_read_map.c \
		ft_check_info.c \
		ft_error.c \
		ft_utils.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \

_SRC = $(addprefix $(PATH), $(SRCS))

OBJ = $(_SRC:.c=.o)

INCLUDES = ./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	gcc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
