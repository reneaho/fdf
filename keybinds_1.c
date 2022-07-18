/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:34:36 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 15:02:27 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	enlarge_map_z(t_node *tool)
{
	if ((tool->last_key == LINUX_U || tool->last_key == MAC_U) && \
				(tool->tile_depth > -2147483630))
		tool->tile_depth = tool->tile_depth - 10;
	if ((tool->last_key == LINUX_O || tool->last_key == MAC_O) && \
				(tool->tile_depth < 2147483630))
		tool->tile_depth = tool->tile_depth + 10;
}

static void	enlarge_map_xyz(t_node *tool)
{
	erase_map(tool);
	enlarge_map_z(tool);
	if (tool->last_key == LINUX_J || tool->last_key == MAC_J)
	{
		if (tool->tile_width > 6)
			tool->tile_width = tool->tile_width - 6;
		else
			tool->tile_width = 0;
	}
	if ((tool->last_key == LINUX_L || tool->last_key == MAC_L) && \
				(tool->tile_width < 2147483630))
		tool->tile_width = tool->tile_width + 6;
	if (tool->last_key == LINUX_I || tool->last_key == MAC_I)
	{
		if (tool->tile_height > 6)
			tool->tile_height = tool->tile_height - 6;
		else
			tool->tile_height = 0;
	}
	if ((tool->last_key == LINUX_K || tool->last_key == MAC_K) && \
				(tool->tile_height < 2147483630))
		tool->tile_height = tool->tile_height + 6;
	draw_map(tool);
}

void	keybinds_1(t_node *tool)
{
	if (tool->last_key == LINUX_J || tool->last_key == MAC_J || \
		tool->last_key == LINUX_L || tool->last_key == MAC_L || \
		tool->last_key == LINUX_I || tool->last_key == MAC_I || \
		tool->last_key == LINUX_K || tool->last_key == MAC_K || \
		tool->last_key == LINUX_U || tool->last_key == MAC_U || \
		tool->last_key == LINUX_O || tool->last_key == MAC_O)
		enlarge_map_xyz(tool);
}
