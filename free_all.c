/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:04:56 by raho              #+#    #+#             */
/*   Updated: 2022/07/22 20:22:01 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit_free(t_node *tool)
{
	ft_putendl_fd("Error", 2);
	free_all(tool);
	exit(1);
}

void	free_all(t_node *tool)
{
	int	index;

	index = 0;
	if (tool->char_matrix)
	{
		while (index < tool->height)
		{
			free(tool->char_matrix[index]);
			if (tool->int_matrix)
				free(tool->int_matrix[index]);
			index++;
		}
		free(tool->char_matrix);
		if (tool->int_matrix)
			free(tool->int_matrix);
	}
}
