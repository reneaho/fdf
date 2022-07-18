/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 15:02:27 by raho             ###   ########.fr       */
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
			ft_putendl("Bad map");
		else
			do_events(&tool);
		free_all(&tool);
	}
	else
		ft_putendl("usage: ./fdf map_file");
	return (0);
}
