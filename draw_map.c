/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:10:26 by raho              #+#    #+#             */
/*   Updated: 2022/08/03 19:13:07 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	choose_color_right(t_node *tool, int map_x, int map_y)
{
	if (tool->int_matrix[map_y][map_x] > 0)
	{
		if (tool->int_matrix[map_y][map_x] == \
				tool->int_matrix[map_y][map_x + 1])
			tool->color = COLOR_POSITIVE;
		else
			tool->color = COLOR_TRANSITION;
	}
	else if (tool->int_matrix[map_y][map_x] < 0)
	{
		if (tool->int_matrix[map_y][map_x] == \
				tool->int_matrix[map_y][map_x + 1])
			tool->color = COLOR_NEGATIVE;
		else
			tool->color = COLOR_TRANSITION;
	}
	else if (tool->int_matrix[map_y][map_x + 1] == 0)
		tool->color = COLOR_NEUTRAL;
	else
		tool->color = COLOR_TRANSITION;
}

static void	choose_color_down(t_node *tool, int map_x, int map_y)
{
	if (tool->int_matrix[map_y][map_x] > 0)
	{
		if (tool->int_matrix[map_y][map_x] == \
				tool->int_matrix[map_y + 1][map_x])
			tool->color = COLOR_POSITIVE;
		else
			tool->color = COLOR_TRANSITION;
	}
	else if (tool->int_matrix[map_y][map_x] < 0)
	{
		if (tool->int_matrix[map_y][map_x] == \
				tool->int_matrix[map_y + 1][map_x])
			tool->color = COLOR_NEGATIVE;
		else
			tool->color = COLOR_TRANSITION;
	}
	else if (tool->int_matrix[map_y + 1][map_x] == 0)
		tool->color = COLOR_NEUTRAL;
	else
		tool->color = COLOR_TRANSITION;
}

static void	draw_right(t_node *tool, int map_x, int map_y)
{
	tool->xyz[0] = map_x;
	tool->xyz[1] = map_y;
	tool->xyz[2] = tool->int_matrix[map_y][map_x];
	rotation_matrix(tool);
	tool->x1 = tool->xyz[0] + tool->map_position_w;
	tool->y1 = tool->xyz[1] + tool->map_position_h;
	tool->xyz[0] = map_x + 1;
	tool->xyz[1] = map_y;
	tool->xyz[2] = tool->int_matrix[map_y][map_x + 1];
	rotation_matrix(tool);
	tool->x2 = tool->xyz[0] + tool->map_position_w;
	tool->y2 = tool->xyz[1] + tool->map_position_h;
	choose_color_right(tool, map_x, map_y);
	draw_line(tool);
}

static void	draw_down(t_node *tool, int map_x, int map_y)
{
	tool->xyz[0] = map_x;
	tool->xyz[1] = map_y;
	tool->xyz[2] = tool->int_matrix[map_y][map_x];
	rotation_matrix(tool);
	tool->x1 = tool->xyz[0] + tool->map_position_w;
	tool->y1 = tool->xyz[1] + tool->map_position_h;
	tool->xyz[0] = map_x;
	tool->xyz[1] = map_y + 1;
	tool->xyz[2] = tool->int_matrix[map_y + 1][map_x];
	rotation_matrix(tool);
	tool->x2 = tool->xyz[0] + tool->map_position_w;
	tool->y2 = tool->xyz[1] + tool->map_position_h;
	choose_color_down(tool, map_x, map_y);
	draw_line(tool);
}

void	draw_map(t_node *tool)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	if (tool->width == 1 && tool->height == 1)
		draw_one(tool);
	else
	{
		while (map_y < tool->height)
		{
			map_x = 0;
			while (map_x < tool->width)
			{
				if (map_x != tool->width - 1)
					draw_right(tool, map_x, map_y);
				if (map_y != tool->height - 1)
					draw_down(tool, map_x, map_y);
				map_x++;
			}
			map_y++;
		}
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
									tool->img_ptr, 0, 0);
}
