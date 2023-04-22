/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _3d_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:19:02 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/07 18:19:05 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	set_texture(t_data *data)
{
	if (!data->side && data->step_x == -1)
	{
		data->texheight = data->north.h;
		data->texwidth = data->north.w;
		data->arr = (int *)data->north.addr;
	}
	if (data->side && data->step_y == -1)
	{
		data->texheight = data->west.h;
		data->texwidth = data->west.w;
		data->arr = (int *)data->west.addr;
	}
	if (!data->side && data->step_x == 1)
	{
		data->texheight = data->south.h;
		data->texwidth = data->south.w;
		data->arr = (int *)data->south.addr;
	}
	if (data->side && data->step_y == 1)
	{
		data->texheight = data->east.h;
		data->texwidth = data->east.w;
		data->arr = (int *)data->east.addr;
	}
}

void	get_tx_color_cords(t_data *data)
{
	if (!data->side)
		data->wallx = data->pos_y + data->perpwalldist * data->raydir_y;
	else
		data->wallx = data->pos_x + data->perpwalldist * data->raydir_x;
	data->wallx -= (int)floor(data->wallx);
	data->tex_x = (int)(data->wallx * (double)data->texwidth);
	if (!data->side && data->raydir_x > 0)
		data->tex_x = data->texwidth - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = data->texwidth - data->tex_x - 1;
	data->step = 1.0 * data->texheight / data->line_h;
	data->texpos = (data->drawstart - data->h / 2
			+ data->line_h / 2) * data->step;
}

void	draw_line(t_data *data, int x)
{
	int	i;
	int	b;

	b = 0;
	i = -1;
	while (++i < data->drawstart)
		img_pix_put(data->img, x, i, data->ceiling);
	i--;
	while (i++ < data->drawend)
	{
		data->tex_y = (int)data->texpos;
		if (data->tex_y >= data->texheight)
			data->tex_y = data->texheight - 1;
		data->texpos += data->step;
		b = data->arr[data->texheight * data->tex_y + data->tex_x];
		img_pix_put(data->img, x, i, b);
	}
	i = data->drawend;
	while (++i < data->h)
		img_pix_put(data->img, x, i, data->floor);
}

void	_3d(t_data *data, int x)
{
	data->line_h = (int)(data->h / data->perpwalldist);
	data->drawstart = -data->line_h / 2 + data->h / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->line_h / 2 + data->h / 2;
	if (data->drawend >= data->h)
		data->drawend = data->h - 1;
	set_texture(data);
	get_tx_color_cords(data);
	draw_line(data, x);
}
