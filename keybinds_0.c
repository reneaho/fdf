/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:30:31 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 12:02:41 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	free_all(tool);
	exit (0);
}

void	erase_map(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_SIZE_WIDTH)
		{
			tool->color = 0x000000;
			image_pixel_put(tool, x, y);
			x++;
		}
		y++;
	}
}

static void	move_map(t_node *tool)
{
	erase_map(tool);
	if ((tool->last_key == LINUX_LEFT || tool->last_key == MAC_LEFT) && \
				(tool->map_position_w > -2147483580))
		tool->map_position_w = tool->map_position_w - 50;
	if ((tool->last_key == LINUX_RIGHT || tool->last_key == MAC_RIGHT) && \
				(tool->map_position_w < 2147483580))
		tool->map_position_w = tool->map_position_w + 50;
	if ((tool->last_key == LINUX_UP || tool->last_key == MAC_UP) && \
				(tool->map_position_h > -2147483580))
		tool->map_position_h = tool->map_position_h - 50;
	if ((tool->last_key == LINUX_DOWN || tool->last_key == MAC_DOWN) && \
				(tool->map_position_h < 2147483580))
		tool->map_position_h = tool->map_position_h + 50;
	draw_map(tool);
}

static void	rotate_map(t_node *tool)
{
	erase_map(tool);
	if ((tool->last_key == LINUX_A || tool->last_key == MAC_A) && \
				(tool->beta > -2147483630))
		tool->beta = tool->beta - 5;
	if ((tool->last_key == LINUX_D || tool->last_key == MAC_D) && \
				(tool->beta < 2147483630))
		tool->beta = tool->beta + 5;
	if ((tool->last_key == LINUX_W || tool->last_key == MAC_W) && \
				(tool->gamma > -2147483630))
		tool->gamma = tool->gamma + 5;
	if ((tool->last_key == LINUX_S || tool->last_key == MAC_S) && \
				(tool->gamma < 2147483630))
		tool->gamma = tool->gamma - 5;
	if (tool->last_key == LINUX_Q || tool->last_key == MAC_Q)
		tool->alpha = tool->alpha - 5;
	if (tool->last_key == LINUX_E || tool->last_key == MAC_E)
		tool->alpha = tool->alpha + 5;
	draw_map(tool);
}

void	keybinds_0(t_node *tool)
{
	if (tool->last_key == LINUX_ENTER || tool->last_key == MAC_ENTER)
	{
		erase_map(tool);
		reinitialize_struct(tool);
		draw_map(tool);
	}
	if (tool->last_key == LINUX_ESC || tool->last_key == MAC_ESC)
		close_program(tool);
	if (tool->last_key == LINUX_A || tool->last_key == MAC_A || \
		tool->last_key == LINUX_W || tool->last_key == MAC_W || \
		tool->last_key == LINUX_D || tool->last_key == MAC_D || \
		tool->last_key == LINUX_S || tool->last_key == MAC_S || \
		tool->last_key == LINUX_Q || tool->last_key == MAC_Q || \
		tool->last_key == LINUX_E || tool->last_key == MAC_E)
		rotate_map(tool);
	if (tool->last_key == LINUX_LEFT || tool->last_key == MAC_LEFT || \
		tool->last_key == LINUX_UP || tool->last_key == MAC_UP || \
		tool->last_key == LINUX_RIGHT || tool->last_key == MAC_RIGHT || \
		tool->last_key == LINUX_DOWN || tool->last_key == MAC_DOWN)
		move_map(tool);
	keybinds_1(tool);
}
