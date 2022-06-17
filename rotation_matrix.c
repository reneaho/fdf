/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:37:01 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:37:08 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_node *tool)
{
	float	temp[3];
	double	alpha;

	alpha = (tool->alpha * M_PI) / 180;
	temp[0] = tool->xyz[0];
	temp[1] = tool->xyz[1];
	temp[2] = tool->xyz[2];
	tool->xyz[0] = (temp[0] * cos(alpha)) + (temp[1] * -sin(alpha)) + 0;
	tool->xyz[1] = (temp[0] * sin(alpha)) + (temp[1] * cos(alpha)) + 0;
	tool->xyz[2] = 0 + 0 + (temp[2] * 1);
}

static void	rotate_y(t_node *tool)
{
	float	temp[3];
	double	beta;

	beta = (tool->beta * M_PI) / 180;
	temp[0] = tool->xyz[0];
	temp[1] = tool->xyz[1];
	temp[2] = tool->xyz[2];
	tool->xyz[0] = (temp[0] * cos(beta)) + 0 + (temp[2] * sin(beta));
	tool->xyz[1] = 0 + (temp[1] * 1) + 0;
	tool->xyz[2] = (temp[0] * -sin(beta)) + 0 + (temp[2] * cos(beta));
}

static void	rotate_x(t_node *tool)
{
	float	temp[3];
	double	gamma;

	gamma = (tool->gamma * M_PI) / 180;
	temp[0] = tool->xyz[0];
	temp[1] = tool->xyz[1];
	temp[2] = tool->xyz[2];
	tool->xyz[0] = (temp[0] * 1) + 0 + 0;
	tool->xyz[1] = 0 + (temp[1] * cos(gamma)) + (temp[2] * -sin(gamma));
	tool->xyz[2] = 0 + (temp[1] * sin(gamma)) + (temp[2] * cos(gamma));
}

void	rotation_matrix(t_node *tool)
{
	tool->xyz[0] = tool->xyz[0] * tool->tile_width;
	tool->xyz[1] = tool->xyz[1] * tool->tile_height;
	tool->xyz[2] = tool->xyz[2] * tool->tile_depth;
	rotate_z(tool);
	rotate_y(tool);
	rotate_x(tool);
}
