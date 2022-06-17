/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:28 by raho              #+#    #+#             */
/*   Updated: 2022/05/26 18:20:55 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_keybinds(void)
{
	ft_putendl("LeftArrow - Move map left");
	ft_putendl("UpArrow - Move map up");
	ft_putendl("RightArrow - Move map right");
	ft_putendl("DownArrow - Move map down");
	ft_putendl("A - Rotate map left");
	ft_putendl("W - Rotate map up");
	ft_putendl("D - Rotate map right");
	ft_putendl("S - Rotate map down");
	ft_putendl("U - Decrease tile z");
	ft_putendl("O - Increase tile z");
	ft_putendl("J - Decrease tile x");
	ft_putendl("I - Decrease tile y");
	ft_putendl("L - Increase tile x");
	ft_putendl("K - Increase tile y");
	ft_putendl("ENTER - Resets the map");
	ft_putendl("ESC - Quit the program");
}

int	key_press(int key, void *param)
{
	t_node		*tool;

	tool = (t_node *)param;
	tool->last_key = key;
	keybinds_0(tool);
	return (0);
}	

void	do_events(t_node *tool)
{
	tool->mlx_ptr = mlx_init();
	tool->win_ptr = mlx_new_window(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, "fdf");
	tool->img_ptr = mlx_new_image(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	tool->img_addr = mlx_get_data_addr(tool->img_ptr, &tool->bits_per_pixel, &tool->size_line, &tool->endian);
	draw_map(tool);
	print_keybinds();
	mlx_key_hook(tool->win_ptr, key_press, (void *)tool);
	mlx_loop(tool->mlx_ptr);
}
