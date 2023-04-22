/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:00:45 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/10 03:00:45 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_cl_val(t_p *data)
{
	if (data->red_cl < 0 || data->red_cl > 255)
		return (0);
	if (data->green_cl < 0 || data->green_cl > 255)
		return (0);
	if (data->blue_cl < 0 || data->blue_cl > 255)
		return (0);
	return (1);
}

int	check_fl_val(t_p *data)
{
	if (data->red_fl < 0 || data->red_fl > 255)
		return (0);
	if (data->green_fl < 0 || data->green_fl > 255)
		return (0);
	if (data->blue_fl < 0 || data->blue_fl > 255)
		return (0);
	return (1);
}

int	check_cl_color(char *check, t_p *data)
{
	int	i;
	int	blue_flag;

	i = 1;
	blue_flag = 1;
	if (check[i++] != ' ')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->red_cl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	if (check[i++] != ',')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->green_cl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	blue_flag = check_bleu_cl(check, data, i);
	if (!blue_flag)
		return (0);
	return (check_cl_val(data));
}

int	check_fl_color(char *check, t_p *data)
{
	int	i;
	int	blue_flag;

	i = 1;
	blue_flag = 1;
	if (check[i++] != ' ')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->red_fl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	if (check[i++] != ',')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->green_fl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	blue_flag = check_bleu_fl(check, data, i);
	if (!blue_flag)
		return (0);
	return (check_fl_val(data));
}

int	check_colors(char **check, t_p *data, int *i, int *c)
{
	if (check[(*i)][0] == 'F')
	{
		if (data->red_fl || data->green_fl || data->blue_fl)
			return (error_colors(0));
		if (!check_fl_color(check[(*i)], data) || check[(*i)][1] != ' ')
			return (error_colors(1));
		(*c)++;
		(*i)++;
	}
	if (check[(*i)][0] == 'C')
	{
		if (data->red_cl || data->green_cl || data->blue_cl)
			return (error_colors(2));
		if (!check_cl_color(check[(*i)], data) || check[(*i)][1] != ' ' )
			return (error_colors(3));
		(*c)++;
		(*i)++;
	}
	return (1);
}
