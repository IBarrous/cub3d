/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:34:58 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/12 06:19:26 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

char	look_for_dir(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
				return (map[i][j]);
			j++;
		}
		i++;
	}
	return ('\0');
}

int	get_coordinates(char **lines, int option, char c)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == c)
			{
				if (option)
					return (i);
				else
					return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
