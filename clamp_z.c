/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:26:47 by raho              #+#    #+#             */
/*   Updated: 2022/07/19 15:33:21 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculate_lowest_highest(t_node *tool)
{
	int	y;
	int	x;

	tool->lowest = tool->int_matrix[0][0];
	tool->highest = tool->int_matrix[0][0];
	y = 0;
	while (y < tool->height)
	{
		x = 0;
		while (x < tool->width)
		{
			if (tool->lowest > tool->int_matrix[y][x])
				tool->lowest = tool->int_matrix[y][x];
			if (tool->highest < tool->int_matrix[y][x])
				tool->highest = tool->int_matrix[y][x];
			x++;
		}
		y++;
	}
}

void	clamp_z(t_node *tool)
{
	int	y;
	int	x;

	calculate_lowest_highest(tool);
	y = 0;
	while (y < tool->height)
	{
		x = 0;
		while (x < tool->width)
		{
			if (tool->int_matrix[y][x] != 0)
				tool->int_matrix[y][x] = (10 - (-10)) * \
				(tool->int_matrix[y][x] - tool->lowest) / \
				(tool->highest - tool->lowest) + (-10);
			x++;
		}
		y++;
	}
}
