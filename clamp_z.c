/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:55:57 by raho              #+#    #+#             */
/*   Updated: 2022/08/03 19:32:00 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clamp_z(t_node *tool)
{
	int	y;
	int	x;

	y = 0;
	while (y < tool->height)
	{
		x = 0;
		while (x < tool->width)
		{
			if (tool->int_matrix[y][x] > 50000)
				tool->int_matrix[y][x] = 50000;
			if (tool->int_matrix[y][x] < -50000)
				tool->int_matrix[y][x] = 50000;
			x++;
		}
		y++;
	}
}
