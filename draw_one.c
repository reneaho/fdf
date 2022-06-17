#include "fdf.h"

void	draw_one(t_node *tool)
{
	if (check_if_inside(tool->map_position_w, tool->map_position_h))
	{
		if (tool->int_matrix[0][0] > 0)
			tool->color = COLOR_POSITIVE;
		if (tool->int_matrix[0][0] == 0)
			tool->color = COLOR_NEUTRAL;
		if (tool->int_matrix[0][0] < 0)
			tool->color = COLOR_NEGATIVE;
		image_pixel_put(tool, tool->map_position_w, tool->map_position_h);
	}
}
