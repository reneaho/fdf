/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:51 by raho              #+#    #+#             */
/*   Updated: 2022/07/25 12:44:21 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_struct(t_node *tool, char *file_name)
{
	tool->mlx_ptr = NULL;
	tool->win_ptr = NULL;
	tool->img_ptr = NULL;
	tool->file = file_name;
	tool->char_matrix = NULL;
	tool->int_matrix = 0;
	tool->height = 0;
	tool->width = 0;
	tool->width_check = 0;
	tool->img_addr = NULL;
	tool->bits_per_pixel = 0;
	tool->size_line = 0;
	tool->endian = 0;
	tool->last_key = 0;
	tool->color = 0;
	reinitialize_struct(tool);
}

void	reinitialize_struct(t_node *tool)
{
	tool->x = 0;
	tool->y = 0;
	tool->deltax = 0;
	tool->deltay = 0;
	tool->slope = 0;
	tool->parametric_value = 0;
	tool->temp = 0;
	tool->x1 = 0;
	tool->y1 = 0;
	tool->x2 = 0;
	tool->y2 = 0;
	tool->xyz[0] = 0;
	tool->xyz[1] = 0;
	tool->xyz[2] = 0;
	tool->alpha = 0;
	tool->beta = 0;
	tool->gamma = 0;
	tool->tile_width = MAP_START_TILE_WIDTH;
	tool->tile_height = MAP_START_TILE_HEIGHT;
	tool->tile_depth = MAP_START_TILE_DEPTH;
	tool->map_position_w = MAP_START_POSITION_WIDTH;
	tool->map_position_h = MAP_START_POSITION_HEIGHT;
}
