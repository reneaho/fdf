/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:17:11 by raho              #+#    #+#             */
/*   Updated: 2022/07/25 13:14:12 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *str)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (str[index] != '\0')
	{
		while (str[index] == ' ')
			index++;
		if (str[index] != '\0' && str[index] != ' ')
		{
			counter++;
			while (str[index] != '\0' && str[index] != ' ')
				index++;
		}
	}
	return (counter);
}

static int	check_lines_helper(t_node *tool, char **line)
{
	tool->width_check = count_words(*line);
	if (tool->width_check == 0 || tool->width_check != tool->width)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	tool->height = tool->height + 1;
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}

int	check_lines(t_node *tool, int fd, char *line)
{
	int	gnl;

	gnl = get_next_line(fd, &line);
	if (gnl == -1)
		error_exit_free(tool);
	if (line == NULL)
		return (-1);
	tool->width = count_words(line);
	while (gnl > 0)
	{
		if (check_lines_helper(tool, &line) == -1)
			return (-1);
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		error_exit_free(tool);
	return (gnl);
}

int	check_content(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (y < tool->height)
	{
		x = 0;
		while (x < tool->width)
		{
			if (((tool->char_matrix[y][x] != ' ' && \
					tool->char_matrix[y][x] != '-' && \
					(tool->char_matrix[y][x] < 48 || \
					tool->char_matrix[y][x] > 57)) && \
					tool->char_matrix[y][x] != '\n') || \
					(tool->char_matrix[y][x] == '\n' && \
					tool->char_matrix[y][x + 1] != '\0') || \
					(tool->char_matrix[y][x] == '-' && \
					(tool->char_matrix[y][x + 1] < 48 || \
					tool->char_matrix[y][x + 1] > 57)))
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
