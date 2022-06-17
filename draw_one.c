/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:14:21 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:14:55 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_one(t_node *tool)
{
	if (check_if_inside(tool->map_position_w, tool->map_position_h))
	{
		if (tool->int_matrix[0][0] > 0)
			tool->color = COLOR_POSITIVE;
		if (tool->int_matrix[0][0] == 0)
			tool->color = COLOR_NEUTRAL;
		if (tool->int_matrix[0][0] < 0)
			tool->color = COLOR_NEGATIVE;
		image_pixel_put(tool, tool->map_position_w, tool->map_position_h);
	}
}
