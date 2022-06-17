/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:04:56 by raho              #+#    #+#             */
/*   Updated: 2022/05/26 18:47:18 by raho             ###   ########.fr       */
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
			tool->char_matrix[index] = NULL;
			if (tool->int_matrix)
			{
				free(tool->int_matrix[index]);
				tool->int_matrix[index] = 0;
			}
			index++;
		}
		free(tool->char_matrix[index]);
		tool->char_matrix[index] = NULL;
		free(tool->char_matrix);
		tool->char_matrix = NULL;
		if (tool->int_matrix)
		{
			free(tool->int_matrix);
			tool->int_matrix = 0;
		}
	}
}
