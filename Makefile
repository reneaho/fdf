# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <raho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/07/18 11:55:44 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTLIB = ./libft -lft
LIBFTINCL = ./libft
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FDFINCL = ./
SRCS = main.c do_events.c free_all.c initialize_struct.c handle_input.c \
		handle_file.c draw_line.c draw_map.c rotation_matrix.c keybinds_0.c \
		keybinds_1.c draw_one.c image_pixel_put.c file_checks.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	cd libft; make all
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTLIB) -I$(LIBFTINCL) -I$(MLXINCL) \
	-I$(FDFINCL) $(MLXLINK) -o $(NAME)

clean:
	cd libft; make clean
	rm -f $(OBJS)

fclean: clean
	cd libft; make fclean
	rm -f $(NAME)

re: fclean all
	cd libft; make re
