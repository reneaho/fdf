/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:15:26 by raho              #+#    #+#             */
/*   Updated: 2022/07/25 17:36:51 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_SIZE_WIDTH 1400
# define WINDOW_SIZE_HEIGHT 1000
# define MAP_START_TILE_WIDTH 32
# define MAP_START_TILE_HEIGHT 32
# define MAP_START_TILE_DEPTH 5
# define MAP_START_POSITION_WIDTH 0
# define MAP_START_POSITION_HEIGHT 0
# define COLOR_NEUTRAL 0xFFFFFF
# define COLOR_POSITIVE 0xD154E4
# define COLOR_NEGATIVE 0xF51911
# define COLOR_TRANSITION 0xF9D460
# define LINUX_W 119
# define LINUX_A 97
# define LINUX_S 115
# define LINUX_D 100
# define LINUX_Q 113
# define LINUX_E 101
# define LINUX_I 105
# define LINUX_J 106
# define LINUX_K 107
# define LINUX_L 108
# define LINUX_U 117
# define LINUX_O 111
# define LINUX_LEFT 65361
# define LINUX_UP 65362
# define LINUX_RIGHT 65363
# define LINUX_DOWN 65364
# define LINUX_ENTER 65293
# define LINUX_ESC 65307
# define MAC_W 13
# define MAC_A 0
# define MAC_S 1
# define MAC_D 2
# define MAC_Q 12
# define MAC_E 14
# define MAC_I 34
# define MAC_J 38
# define MAC_K 40
# define MAC_L 37
# define MAC_U 32
# define MAC_O 31
# define MAC_LEFT 123
# define MAC_UP 126
# define MAC_RIGHT 124
# define MAC_DOWN 125
# define MAC_ENTER 36
# define MAC_ESC 53

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_node
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*file;
	int		height;
	int		width;
	int		width_check;
	char	**char_matrix;
	int		**int_matrix;
	float	x;
	float	y;
	float	deltax;
	float	deltay;
	float	slope;
	float	parametric_value;
	float	temp;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	xyz[3];
	int		alpha;
	int		beta;
	int		gamma;
	int		tile_width;
	int		tile_height;
	int		tile_depth;
	int		map_position_w;
	int		map_position_h;
	int		color;
	int		last_key;
}			t_node;

void	initialize_struct(t_node *tool, char *file_name);
int		open_map(t_node *tool);
void	close_map(int fd, t_node *tool);
int		handle_input(int fd, t_node *tool);
int		check_lines(t_node *tool, int fd, char *line);
int		check_content(t_node *tool, int y);
int		check_atoi_overflow(char *str);
void	clamp_z(t_node *tool);
void	do_events(t_node *tool);
void	draw_line(t_node *tool);
void	draw_map(t_node *tool);
void	draw_one(t_node *tool);
void	rotation_matrix(t_node *tool);
void	image_pixel_put(t_node *tool, int x, int y);
int		check_if_inside(int x, int y);
void	erase_map(t_node *tool);
void	keybinds_0(t_node *tool);
void	keybinds_1(t_node *tool);
void	reinitialize_struct(t_node *tool);
void	error_exit_free(t_node *tool);
void	free_all(t_node *tool);

#endif
