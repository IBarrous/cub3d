/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:14:22 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/09 12:14:24 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include "parsing/parsing.h"

typedef struct x_list
{
	int		w;
	int		h;
	int		bpp;
	int		size;
	int		endian;
	void	*ptr;
	char	*addr;
}	t_img;

typedef struct t_list
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
	int		*arr;
	t_img	east;
	t_img	west;
	t_img	north;
	t_img	south;
	char	**map;
	int		count;
	int		m;
	double	pos_x;
	double	pos_y;
	int		line_h;
	int		drawstart;
	char	c;
	int		drawend;
	int		texwidth;
	int		texheight;
	char	i_dir;
	double	wallx;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	int		side;
	int		hit;
	int		map_x;
	int		map_y;
	int		step_x;
	double	where;
	double	speed;
	int		step_y;
	double	perpwalldist;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	camera_x;
	double	camera_y;
	double	raydir_x;
	char	dir;
	double	raydir_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		ceiling;
	int		floor;
	int		width;
	double	pov;
	int		x;
	int		y;
	int		w;
	int		h;
	t_p		parse;
}	t_data;

//Movement
void	rotate(t_data *data, double angle);
void	right_key(t_data *data);
void	up_key(t_data *data);
void	left_key(t_data *data);
void	down_key(t_data *data);

//Raycasting
void	cast_rays(t_data *data);

//3d
void	_3d(t_data *data, int x);

void	output(t_data *data, int option);

//Utils
t_data	*init_data(char **map);
int		img_color_get(t_img *img, int x, int y);
char	*ft_itoa(int n);
int		get_color(int r, int g, int b);
//char	*ft_strjoin(char const *s1, char const *s2);
//Map creation
char	look_for_dir(char **map);
char	**map_make(char *map);
void	img_pix_put(t_img img, int x, int y, int color);
void	show_rays(t_data *data);
//Map check
void	map_check_functions(char **lines);
int		count_repetition(char **lines, char c);
void	check_line_size(char **lines);
void	map_check(char **lines);
int		lst_len(char **lines);
void	show_rays(t_data *data);
//Player && Blocks Creation
t_data	make_player(void *mlx, void *mlx_win, char **lines);
int		get_coordinates(char **lines, int option, char c);
void	set_init_dir(t_data *data);
void	draw(t_data *data);
//Movements
int		animation(void *arg);
int		ft_input(int key, void *param);
void	print_moves(t_data	*player);

//Output

void	output_map(char **lines, t_data *player);
int		exit_program(void);

//Animations
int		ft_animation(void *param);
//Libft
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_free(char **strings);

int		get_tx_color(t_data *data, t_img wall, int i);
#endif
