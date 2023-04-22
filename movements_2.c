/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:45:40 by ibarrous          #+#    #+#             */
/*   Updated: 2022/12/17 13:46:25 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	output(t_data *data, int option)
{
	if (option)
	{
		mlx_clear_window(data->mlx, data->win_ptr);
		mlx_destroy_image(data->mlx, data->img.ptr);
	}
	data->img.ptr = NULL;
	data->img.ptr = mlx_new_image(data->win_ptr, data->w, data->h);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.size, &data->img.endian);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.ptr, 0, 0);
}

int	ft_input(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 2)
		right_key(data);
	else if (key == 0)
		left_key(data);
	else if (key == 1)
		up_key(data);
	else if (key == 13)
		down_key(data);
	else if (key == 53)
	{
		mlx_destroy_image(data->mlx, data->img.ptr);
		mlx_destroy_window(data->mlx, data->win_ptr);
		exit(0);
	}
	else if (key == 124)
		rotate(data, data->pov);
	else if (key == 123)
		rotate(data, -data->pov);
	output(data, 1);
	return (0);
}
