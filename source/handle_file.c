/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:23:25 by raho              #+#    #+#             */
/*   Updated: 2022/07/22 19:28:10 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_map(t_node *tool)
{
	int	fd;

	fd = open(tool->file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Couldn't open: ", 2);
		ft_putendl_fd(tool->file, 2);
		free_all(tool);
		exit (1);
	}
	return (fd);
}

void	close_map(int fd, t_node *tool)
{
	if (close(fd) == -1)
	{
		ft_putstr_fd("Closing the file failed", 2);
		free_all(tool);
		exit (1);
	}
}
