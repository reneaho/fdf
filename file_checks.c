/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:17:11 by raho              #+#    #+#             */
/*   Updated: 2022/08/05 21:39:28 by raho             ###   ########.fr       */
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
		while (str[index] == ' ' || str[index] == '\t')
			index++;
		if (str[index] != '\0')
		{
			counter++;
			while (str[index] != '\0' && str[index] != ' ' && \
					str[index] != '\t')
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
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (gnl == -1)
		error_exit_free(tool);
	return (gnl);
}

static int	check_minus(t_node *tool, int y, int x)
{
	if (x == 0)
	{
		if (tool->char_matrix[y][x + 1] >= '0' && \
			tool->char_matrix[y][x + 1] <= '9')
			return (1);
	}
	else if (tool->char_matrix[y][x - 1] == ' ')
	{
		if (tool->char_matrix[y][x + 1] >= '0' && \
			tool->char_matrix[y][x + 1] <= '9')
			return (1);
	}
	return (0);
}

int	check_content(t_node *tool, int y)
{
	int	pass;
	int	x;

	while (y < tool->height)
	{
		x = 0;
		while (tool->char_matrix[y][x] != '\0')
		{
			pass = 0;
			if (tool->char_matrix[y][x] == ' ')
				pass = 1;
			if (tool->char_matrix[y][x] == '\t')
				pass = 1;
			if (tool->char_matrix[y][x] == '-')
				pass = check_minus(tool, y, x);
			if (tool->char_matrix[y][x] >= '0' && \
				tool->char_matrix[y][x] <= '9')
				pass = 1;
			if (pass == 0)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
