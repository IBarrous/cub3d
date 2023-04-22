/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:00:56 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/10 03:00:56 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_txt_horiz(char **txt, t_p *data, int *i, int *c)
{
	if (txt[(*i)][0] == 'N' && txt[(*i)][1] == 'O')
	{
		if (data->n)
			return (texture_error(0));
		if (!north_textures(txt[(*i)], data) || txt[(*i)][2] != ' ')
		{
			return (texture_error(4));
		}
		(*c)++;
		(*i)++;
	}
	if (txt[(*i)][0] == 'S' && txt[(*i)][1] == 'O')
	{
		if (data->s)
			return (texture_error(1));
		if (!south_textures(txt[(*i)], data) || txt[(*i)][2] != ' ')
			return (texture_error(4));
		(*c)++;
		(*i)++;
	}
	return (1);
}

int	is_txt_vert(char **txt, t_p *data, int *i, int *c)
{
	if (txt[(*i)][0] == 'W' && txt[(*i)][1] == 'E')
	{
		if (data->w)
			return (texture_error(2));
		if (!western_textures(txt[(*i)], data) || txt[(*i)][2] != ' ')
			return (texture_error(4));
		(*c)++;
		(*i)++;
	}
	if (txt[(*i)][0] == 'E' && txt[(*i)][1] == 'A')
	{
		if (data->e)
			return (texture_error(3));
		if (!east_textures(txt[(*i)], data) || txt[(*i)][2] != ' ')
			return (texture_error(4));
		(*c)++;
		(*i)++;
	}
	return (1);
}

int	check_txt(char	**txt, t_p *data, int *i, int *c)
{
	if (!is_txt_horiz(txt, data, i, c))
		return (0);
	if (!is_txt_vert(txt, data, i, c))
		return (0);
	return (1);
}
