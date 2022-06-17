/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:23:25 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:24:11 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_map(t_node *tool)
{
	int	fd;

	fd = open(tool->file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Couldn't open: ");
		ft_putendl(tool->file);
		exit (0);
	}
	return (fd);
}

void	close_map(int fd, t_node *tool)
{
	if (close(fd) == -1)
	{
		free_all(tool);
		exit (0);
	}
}
