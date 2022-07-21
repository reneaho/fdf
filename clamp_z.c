/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:26:47 by raho              #+#    #+#             */
/*   Updated: 2022/07/21 13:23:36 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/* Trying to scale the numbers down but problem is rounding and if the values
	are all positive or all negative. That could be maybe solved with adding
	the minimum or maximum value after the scaling depending if the values
	are all negative or all positive.
*/

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
/*
static float	map_negative(t_node *tool, int y, int x)
{
	float	a;
	float	b;
	float	c;
	float	result;

	a = tool->int_matrix[y][x] - tool->lowest;
	b = -1 - tool->lowest;
	c = -1 - (-10);
	result = a / b * c + (-10);
	//result = ((tool->int_matrix[y][x] - tool->lowest) / (-1 - (tool->lowest)) * (-1 - (-10))) + (-10);
	return (result);
}

static float	map_positive(t_node *tool, int y, int x)
{
	float	a;
	float	b;
	float	c;
	float	result;

	a = tool->int_matrix[y][x] - 1;
	b = tool->highest - 1;
	c = 10 - 1;
	result = a / b * c + 1;
	//result = ((tool->int_matrix[y][x] - 1) / (tool->highest - 1) * (10 - 1)) + 1;
	return (result);
}
*/

/*
static int	round_value(float nb)
{
	
	return (result);
}
*/

static int	map_value(t_node *tool, int y, int x)
{
	float	a;
	float	b;
	float	c;
	float	result;

	a = tool->int_matrix[y][x] - tool->lowest;
	b = tool->highest - tool->lowest;
	c = 10 - (-10);
	result = a / b * c + (-10);
	if (tool->lowest >= 0)
	return (result);
}

void	clamp_z(t_node *tool)
{
	int		y;
	int		x;
	int		scaled_number;
	static int	index;

	calculate_lowest_highest(tool);
	y = 0;
	while (y < tool->height)
	{
		x = 0;
		while (x < tool->width)
		{
			if (index == 16)
			{
				printf("\n");
				index = 0;
			}
			/*
			if (tool->int_matrix[y][x] < 0)
				scaled_number = map_negative(tool, y, x);
			if (tool->int_matrix[y][x] > 0)
				scaled_number = map_positive(tool, y, x);
			*/
			scaled_number = map_value(tool, y, x);
			printf("%.2f ", scaled_number);
			index++;
			tool->int_matrix[y][x] = scaled_number;
			x++;
		}
		y++;
	}
}
