/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/08/01 18:32:15 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_node	tool;
	int		fd;
	int		result;

	fd = 0;
	if (argc == 2)
	{
		initialize_struct(&tool, argv[1]);
		fd = open_map(&tool);
		result = handle_input(fd, &tool);
		close_map(fd, &tool);
		if (result == -1)
			ft_putendl_fd("Bad map", 2);
		else
		{
			clamp_z(&tool);
			do_events(&tool);
		}
		free_all(&tool);
	}
	else
		ft_putendl_fd("usage: ./fdf map_file", 2);
	return (0);
}
