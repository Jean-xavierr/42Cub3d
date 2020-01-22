# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by jereligi          #+#    #+#              #
#    Updated: 2020/01/22 15:11:55 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

PATH = ./srcs/

SRCS =	Cub3d.c \
		ft_read_map.c \
		ft_parse_info.c \
		ft_parse_map.c \
		ft_get_info.c \
		ft_error.c \
		ft_init.c \
		ft_utils.c \
		ft_split.c \
		ft_strdup_map.c \
		ft_strcpy.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_map_2D.c \
		ft_fill_map.c \
		ft_keyboard_action.c \
		ft_move_player_mini_map.c \
		ft_exit_prog.c \
		ft_raycaster.c \

_SRC = $(addprefix $(PATH), $(SRCS))

OBJ = $(_SRC:.c=.o)

INCLUDES = ./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	gcc -o $(NAME) -lm -lmlx -framework OpenGL -framework AppKit $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
