/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:15:43 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/12 03:09:58 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.size + x * (img.bpp / 8));
	*(int *)pixel = color;
}

int	exit_program(void)
{
	exit(1);
}

void	*my_xpm_to_img(void	*mlx, char *file, int *width, int *height)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx, file,
			width, height);
	if (!ptr)
	{
		printf("\"%s\" is an unsupported / non existent texture !\n", file + 2);
		exit(1);
	}
	return (ptr);
}

void	init_tex(t_data *data)
{
	data->south.ptr = my_xpm_to_img(data->mlx, data->parse.s,
			&data->south.w, &data->south.h);
	data->east.ptr = my_xpm_to_img(data->mlx, data->parse.e,
			&data->east.w, &data->east.h);
	data->north.ptr = my_xpm_to_img(data->mlx, data->parse.n,
			&data->north.w, &data->north.h);
	data->west.ptr = my_xpm_to_img(data->mlx, data->parse.w,
			&data->west.w, &data->west.h);
	data->north.addr = mlx_get_data_addr(data->north.ptr, &data->north.bpp,
			&data->north.size, &data->north.endian);
	data->east.addr = mlx_get_data_addr(data->east.ptr, &data->east.bpp,
			&data->east.size, &data->east.endian);
	data->west.addr = mlx_get_data_addr(data->west.ptr, &data->west.bpp,
			&data->west.size, &data->west.endian);
	data->south.addr = mlx_get_data_addr(data->south.ptr, &data->south.bpp,
			&data->south.size, &data->south.endian);
	data->ceiling = get_color(data->parse.red_cl,
			data->parse.green_cl, data->parse.blue_cl);
	data->floor = get_color(data->parse.red_fl,
			data->parse.green_fl, data->parse.blue_fl);
}

t_data	*init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->parse = map_parse(av);
	data->w = 1400;
	data->h = 1000;
	data->arr = NULL;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
	data->dir_x = 1.0;
	data->dir_y = 0.0;
	data->mlx = mlx_init();
	init_tex(data);
	data->map = data->parse.map_cont;
	data->i_dir = look_for_dir(data->parse.map_cont);
	data->y = get_coordinates(data->parse.map_cont, 0, data->i_dir);
	data->pov = 0.5;
	data->speed = 0.8;
	data->x = get_coordinates(data->parse.map_cont, 1, data->i_dir);
	data->pos_x = data->x;
	data->pos_y = data->y;
	set_init_dir(data);
	data->win_ptr = mlx_new_window(data->mlx, data->w,
			data->h, "cub3d");
	return (data);
}
