/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:05:05 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:10:01 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	positive_negative_undefined_slope_2(t_node *tool)
{
	if (tool->slope < 1 && tool->y1 < tool->y2)
		tool->y = tool->y + 1;
	else
		tool->y = tool->y - 1;
	tool->parametric_value = tool->parametric_value + 2 * \
							tool->deltay - 2 * tool->deltax;
}

static void	positive_negative_undefined_slope_1(t_node *tool)
{
	if (tool->x1 > tool->x2)
	{
		tool->temp = tool->x1;
		tool->x1 = tool->x2;
		tool->x2 = tool->temp;
		tool->temp = tool->y1;
		tool->y1 = tool->y2;
		tool->y2 = tool->temp;
	}
	tool->deltax = ft_fabs(tool->x2 - tool->x1);
	tool->deltay = ft_fabs(tool->y2 - tool->y1);
	tool->parametric_value = 2 * tool->deltay - tool->deltax;
	tool->x = tool->x1;
	tool->y = tool->y1;
	while (tool->x <= tool->x2)
	{
		if (check_if_inside(tool->x, tool->y))
			image_pixel_put(tool, (int)tool->x, (int)tool->y);
		tool->x = tool->x + 1;
		if (tool->parametric_value >= 0)
			positive_negative_undefined_slope_2(tool);
		else
			tool->parametric_value = tool->parametric_value + 2 * tool->deltay;
	}
}

static void	negative_slope_2(t_node *tool)
{
	if (tool->slope >= 1)
		tool->x = tool->x + 1;
	else
		tool->x = tool->x - 1;
	tool->parametric_value = tool->parametric_value + 2 * \
							tool->deltax - 2 * tool->deltay;
}

static void	negative_slope_1(t_node *tool)
{
	if (tool->y1 > tool->y2)
	{
		tool->temp = tool->x1;
		tool->x1 = tool->x2;
		tool->x2 = tool->temp;
		tool->temp = tool->y1;
		tool->y1 = tool->y2;
		tool->y2 = tool->temp;
	}
	tool->deltax = ft_fabs(tool->x2 - tool->x1);
	tool->deltay = ft_fabs(tool->y2 - tool->y1);
	tool->parametric_value = 2 * tool->deltax - tool->deltay;
	tool->x = tool->x1;
	tool->y = tool->y1;
	while (tool->y <= tool->y2)
	{
		if (check_if_inside(tool->x, tool->y))
			image_pixel_put(tool, (int)tool->x, (int)tool->y);
		tool->y = tool->y + 1;
		if (tool->parametric_value >= 0)
			negative_slope_2(tool);
		else
			tool->parametric_value = tool->parametric_value + 2 * tool->deltax;
	}
}

void	draw_line(t_node *tool)
{
	float	deltax;
	float	deltay;

	deltax = tool->x2 - tool->x1;
	deltay = tool->y2 - tool->y1;
	if (deltax == 0)
		tool->slope = deltay;
	else
		tool->slope = deltay / deltax;
	if (ft_fabs(tool->slope) < 1)
		positive_negative_undefined_slope_1(tool);
	if (ft_fabs(tool->slope) >= 1)
		negative_slope_1(tool);
}
