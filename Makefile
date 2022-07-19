# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <raho@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/07/19 12:48:40 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
LIBFTINCL = libft/
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FDFINCL = ./
SRCS = main.c do_events.c free_all.c initialize_struct.c handle_input.c \
		handle_file.c draw_line.c draw_map.c rotation_matrix.c keybinds_0.c \
		keybinds_1.c draw_one.c image_pixel_put.c file_checks.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(SRCS) $(LIB) $(LIBFTINCL)
	$(CC) $(CFLAGS) $(SRCS) -c
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(LIBFTINCL) -I $(MLXINCL) \
	-I $(FDFINCL) $(MLXLINK) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
