/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:30:39 by raho              #+#    #+#             */
/*   Updated: 2022/05/26 18:58:28 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_char_matrix(t_node *tool)
{
	int	index;

	tool->char_matrix = (char **)malloc(sizeof(char *) * (tool->height + 1));
	if (tool->char_matrix == NULL)
		exit (0);
	index = 0;
	while (index < (tool->height + 1))
	{
		tool->char_matrix[index] = NULL;
		index++;
	}
}

static int	save_map(t_node *tool, int fd, char *line)
{
	int	gnl;
	int	index;

	index = 0;
	gnl = get_next_line(fd, &line);
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
		index++;
		gnl = get_next_line(fd, &line);
	}
	return (gnl);
}

static int	copy_matrix_to_int(t_node *tool, int cy, int iy)
{
	int	cx;
	int	ix;

	while (tool->char_matrix[cy] != 0)
	{
		cx = 0;
		ix = 0;
		while (tool->char_matrix[cy][cx] != '\0')
		{
			while (tool->char_matrix[cy][cx] == ' ')
				cx++;
			if (check_atoi_overflow(&tool->char_matrix[cy][cx]) == -1)
				return (-1);
			tool->int_matrix[iy][ix] = ft_atoi(&tool->char_matrix[cy][cx]);
			while (tool->char_matrix[cy][cx] != '\0' && \
					tool->char_matrix[cy][cx] != ' ')
				cx++;
			ix++;
		}
		cy++;
		iy++;
	}
	return (0);
}

static void	create_int_matrix(t_node *tool)
{
	int	index;

	tool->int_matrix = (int **)malloc(sizeof(int *) * tool->height);
	if (tool->int_matrix == NULL)
		exit (0);
	index = 0;
	while (index < tool->height)
	{
		tool->int_matrix[index] = (int *)malloc(sizeof(int) * tool->width);
		if (tool->int_matrix == NULL)
			exit (0);
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
	if (check_content(tool) == -1)
		return (-1);
	create_int_matrix(tool);
	if (copy_matrix_to_int(tool, 0, 0) == -1)
		return (-1);
	return (0);
}
