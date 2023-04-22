/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:13:16 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 05:52:40 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	error_pars(void)
{
	write(2, "\033[1;31mError: parsing failed\n", 30);
	return (0);
}

int	error_colors(int mode)
{
	if (!mode)
		write(2, "\033[1;31mError: Multi floor colors\n", 34);
	if (mode == 1)
		write(2, "\033[1;31mError: Invalid value of color floor's\n", 46);
	if (mode == 2)
		write(2, "\033[1;31mError: Multi ceil colors\n", 33);
	if (mode == 3)
		write(2, "\033[1;31mError: Invalid value of color ceil's\n", 43);
	if (mode == 4)
	{
		write(2, "\033[1;31mError: Floor colors must have 3 max values\n", 51);
		exit(1);
	}
	if (mode == 5)
	{
		write(2, "\033[1;31mError: Ceil colors must have 3 max values\n", 50);
		exit(1);
	}
	return (0);
}

int	map_error(int mode)
{
	if (!mode)
		write(2, "\033[1;31mError: Invalid MAP!\n", 28);
	if (mode == 1)
		write(2, "\033[1;31mError: Invalid map extension!\n", 38);
	if (mode == 2)
		write(2, "\033[1;31mError: Invalid characters!\n", 35);
	if (mode == 3)
		write(2, "\033[1;31mError: No characters exist!\n", 36);
	if (mode == 4)
		write(2, "\033[1;31mError: Invalid Map!\n", 28);
	return (0);
}

int	texture_error(int mode)
{
	if (!mode)
		write(2, "\033[1;31mError: Multi textures for NO!\n", 38);
	if (mode == 1)
		write(2, "\033[1;31mError: Multi textures for SO!\n", 38);
	if (mode == 2)
		write(2, "\033[1;31mError: Multi textures for WE!\n", 38);
	if (mode == 3)
		write(2, "\033[1;31mError: Multi textures for EA!\n", 38);
	if (mode == 4)
		write(2, "\033[1;31mError: invalid textures\n", 32);
	return (0);
}
