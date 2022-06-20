# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/05/23 19:31:29 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LINUXMATH = -lm
LIBFTLIB = ./libft -lft
LIBFTINCL = ./libft
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FDFINCL = ./
SRCS = main.c do_events.c free_all.c initialize_struct.c handle_input.c \
		handle_file.c draw_line.c draw_map.c rotation_matrix.c keybinds_0.c \
		keybinds_1.c draw_one.c image_pixel_put.c file_checks.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFTLIB) -I$(LIBFTINCL) \
	$(LINUXMATH) -I$(MLXINCL) -I$(FDFINCL) $(MLXLINK) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
