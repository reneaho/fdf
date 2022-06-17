/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:04:56 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:23:05 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_node *tool)
{
	int	index;

	index = 0;
	if (tool->char_matrix)
	{
		while (tool->char_matrix[index] != NULL)
		{
			free(tool->char_matrix[index]);
			if (tool->int_matrix)
				free(tool->int_matrix[index]);
			index++;
		}
		free(tool->char_matrix[index]);
		free(tool->char_matrix);
		if (tool->int_matrix)
			free(tool->int_matrix);
	}
}
