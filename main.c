/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:36:45 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_node	tool;
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		initialize_struct(&tool, argv[1]);
		fd = open_map(&tool);
		if (handle_input(fd, &tool) == -1)
		{
			ft_putendl("Bad map");
			close_map(fd, &tool);
			free_all(&tool);
			return (0);
		}
		close_map(fd, &tool);
		do_events(&tool);
	}
	else
		ft_putendl("usage: ./fdf map_file");
	if (tool.char_matrix != NULL)
		free_all(&tool);
	return (0);
}
