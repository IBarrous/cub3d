/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:42:30 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/07 15:42:32 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	east(t_data *data)
{
	data->pos_x += 0.297992;
	data->pos_y += 0.641093;
	data->dir_x = -0.029200;
	data->dir_y = 0.999574;
	data->plane_x = -0.659719;
	data->plane_y = -0.019272;
}

void	south(t_data *data)
{
	data->pos_x += 0.736849;
	data->pos_y += 0.311535;
}

void	north(t_data *data)
{
	data->pos_x += 0.297992;
	data->pos_y += 0.641093;
	data->dir_x = -0.998295;
	data->dir_y = -0.058375;
	data->plane_x = 0.038527;
	data->plane_y = -0.658875;
}

void	west(t_data *data)
{
	data->pos_x += 0.297992;
	data->pos_y += 0.641093;
	data->dir_x = 0.087500;
	data->dir_y = -0.996165;
	data->plane_x = 0.657469;
	data->plane_y = 0.057749;
}

void	set_init_dir(t_data *data)
{
	if (data->i_dir == 'S')
		south(data);
	else if (data->i_dir == 'E')
		east(data);
	else if (data->i_dir == 'N')
		north(data);
	else if (data->i_dir == 'W')
		west(data);
}
