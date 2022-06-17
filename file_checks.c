/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:17:11 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:19:40 by raho             ###   ########.fr       */
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

int	check_lines(t_node *tool, int fd, char *line)
{
	int	gnl;

	gnl = get_next_line(fd, &line);
	if (line == NULL)
		return (-1);
	tool->width = count_words(line);
	while (gnl > 0)
	{
		tool->width_check = count_words(line);
		if (tool->width_check == 0 || tool->width_check != tool->width)
		{
			free(line);
			line = NULL;
			return (-1);
		}
		tool->height = tool->height + 1;
		if (line)
		{
			free(line);
			line = NULL;
		}
		gnl = get_next_line(fd, &line);
	}
	return (gnl);
}

int	check_atoi_overflow(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 2147483647 && sign == 1)
		return (-1);
	if (res > 2147483648 && sign == -1)
		return (-1);
	return (0);
}

int	check_content(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (tool->char_matrix[y] != 0)
	{
		x = 0;
		while (tool->char_matrix[y][x] != '\0')
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
