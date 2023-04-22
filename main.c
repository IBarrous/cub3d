/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:15 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/12 02:52:36 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		
		data = init_data(av);
		output(data, 0);
		mlx_hook(data->win_ptr, 17, 0, *exit_program, NULL);
		mlx_hook(data->win_ptr, 2, 0, *ft_input, data);
		mlx_loop(data->mlx);
	}
	else
		printf("\033[1;31mError in number of arguments !\n");
	return (0);
}
