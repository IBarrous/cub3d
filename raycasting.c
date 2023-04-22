/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:17:28 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/07 18:17:30 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	raycast(t_data *data, int x)
{
	while (!data->hit)
	{
		if (data->side_y > data->side_x)
		{
			data->side_x += data->delta_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_y += data->delta_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_x][data->map_y] == '1')
			data->hit = 1;
	}
	if (!data->side)
		data->perpwalldist = ((data->map_x + (1 - data->step_x) / 2)
				- data->pos_x) / data->raydir_x;
	else
		data->perpwalldist = ((data->map_y + (1 - data->step_y) / 2)
				- data->pos_y) / data->raydir_y;
	_3d(data, x);
}

void	set_side(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->side_x = (data->pos_x - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->side_x = (data->map_x + 1.0 - data->pos_x) * data->delta_x;
	}		
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->side_y = (data->pos_y - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->side_y = (data->map_y + 1.0 - data->pos_y) * data->delta_y;
	}
}

void	cast_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->w)
	{
		data->camera_x = 2 * x / (double)(data->w) - 1;
		data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
		data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		data->delta_x = sqrt(1 + (data->raydir_y * data->raydir_y)
				/ (data->raydir_x * data->raydir_x));
		data->delta_y = sqrt(1 + (data->raydir_x * data->raydir_x)
				/ (data->raydir_y * data->raydir_y));
		data->hit = 0;
		set_side(data);
		raycast(data, x);
		x++;
	}
}
