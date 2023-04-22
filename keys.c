/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:12:53 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/07 18:12:55 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	rotate(t_data *data, double angle)
{
	double	olddir_x;
	double	oldplanx;

	oldplanx = data->plane_x;
	olddir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(angle) - \
		data->dir_y * sin(angle);
	data->dir_y = olddir_x * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) - \
		data->plane_y * sin(angle);
	data->plane_y = oldplanx * sin(angle) + data->plane_y * cos (angle);
}

void	right_key(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->plane_x * data->speed)]
		[(int)(data->pos_y)] != '1')
		data->pos_x += data->plane_x * data->speed;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y + data->plane_y * data->speed)] != '1')
		data->pos_y += data->plane_y * data->speed;
}

void	up_key(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x * data->speed)]
		[(int)(data->pos_y)] != '1')
		data->pos_x -= data->dir_x * data->speed;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y - data->dir_y * data->speed)] != '1')
		data->pos_y -= data->dir_y * data->speed;
}

void	left_key(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->plane_x * data->speed)]
		[(int)(data->pos_y)] != '1')
		data->pos_x -= data->plane_x * data->speed;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y - data->plane_y * data->speed)] != '1')
		data->pos_y -= data->plane_y * data->speed;
}

void	down_key(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x * data->speed)]
		[(int)(data->pos_y)] != '1')
		data->pos_x += data->dir_x * data->speed;
	if (data->map[(int)(data->pos_x)]
		[(int)(data->pos_y + data->dir_y * data->speed)] != '1')
		data->pos_y += data->dir_y * data->speed;
}
