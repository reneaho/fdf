/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:25:14 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 15:02:27 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_pixel_put(t_node *tool, int x, int y)
{
	char	*pixel;

	pixel = tool->img_addr + (y * tool->size_line + x * \
								(tool->bits_per_pixel / 8));
	*(int *)pixel = tool->color;
}

int	check_if_inside(int x, int y)
{
	if ((x >= 0 && x < WINDOW_SIZE_WIDTH) && (y >= 0 && y < WINDOW_SIZE_HEIGHT))
		return (1);
	else
		return (0);
}
