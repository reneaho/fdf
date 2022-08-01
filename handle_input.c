/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:30:39 by raho              #+#    #+#             */
/*   Updated: 2022/08/01 18:29:21 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_char_matrix(t_node *tool)
{
	int	index;

	tool->char_matrix = (char **)malloc(sizeof(char *) * tool->height);
	if (tool->char_matrix == NULL)
		error_exit_free(tool);
	index = 0;
	while (index < tool->height)
	{
		tool->char_matrix[index] = NULL;
		index++;
	}
}

static int	save_map(t_node *tool, int fd, char *line)
{
	int		gnl;
	int		index;

	index = 0;
	gnl = get_next_line(fd, &line);
	if (gnl == -1)
		error_exit_free(tool);
	if (line == NULL)
		return (-1);
	while (gnl > 0)
	{
		tool->char_matrix[index] = ft_strdup(line);
		if (line)
		{
			free(line);
			line = NULL;
		}
		if (tool->char_matrix[index] == NULL)
			error_exit_free(tool);
		index++;
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		error_exit_free(tool);
	return (gnl);
}

static int	copy_matrix_to_int(t_node *tool, int y, int cx)
{
	int	ix;

	while (y < tool->height)
	{
		cx = 0;
		ix = 0;
		while (tool->char_matrix[y][cx] != '\0')
		{
			while (tool->char_matrix[y][cx] == ' ' || \
					tool->char_matrix[y][cx] == '\t')
				cx++;
			if (tool->char_matrix[y][cx] == '\0')
				break ;
			if (check_atoi_overflow(&tool->char_matrix[y][cx]) == -1)
				return (-1);
			tool->int_matrix[y][ix] = ft_atoi(&tool->char_matrix[y][cx]);
			while (tool->char_matrix[y][cx] != '\0' && \
					(tool->char_matrix[y][cx] != ' ' && \
					tool->char_matrix[y][cx] != '\t'))
				cx++;
			ix++;
		}
		y++;
	}
	return (0);
}

static void	create_int_matrix(t_node *tool)
{
	int	index;

	tool->int_matrix = (int **)malloc(sizeof(int *) * tool->height);
	if (tool->int_matrix == NULL)
		error_exit_free(tool);
	index = 0;
	while (index < tool->height)
	{
		tool->int_matrix[index] = (int *)malloc(sizeof(int) * tool->width);
		if (tool->int_matrix[index] == NULL)
			error_exit_free(tool);
		ft_bzero((int *)tool->int_matrix[index], tool->width);
		index++;
	}
}		

int	handle_input(int fd, t_node *tool)
{
	char	*line;

	line = NULL;
	if (check_lines(tool, fd, line) == -1)
		return (-1);
	close_map(fd, tool);
	fd = open_map(tool);
	create_char_matrix(tool);
	if (save_map(tool, fd, line) == -1)
		return (-1);
	if (check_content(tool, 0) == -1)
		return (-1);
	create_int_matrix(tool);
	if (copy_matrix_to_int(tool, 0, 0) == -1)
		return (-1);
	return (0);
}
