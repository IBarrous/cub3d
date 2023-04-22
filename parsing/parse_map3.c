/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:56:10 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/10 01:56:10 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../cub3d.h"

int	is_map_closed(char	**map)
{
	int	col;

	col = 0;
	while (map[0][col])
	{
		if (ft_strchr("0NSEW", map[0][col]))
		{
			if (!ft_all_sides(map, col))
				return (0);
		}
		col++;
	}
	return (1);
}

int	player_inmap(t_p *data)
{
	if (!data->ply_pos)
		return (0);
	return (1);
}

int	correct_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && !ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	map_validity(char	**map, t_p *data)
{
	int	i;

	i = -1;
	while (map[i + 1] && is_valid_map(map[++i]))
	{
		data->count_cont = i;
		if (i == 0 && !correct_wall(map[i]))
			return (0);
		else if (map[i + 1] && !is_valid_map(map[i + 1]))
		{
			if (i < 2)
				return (0);
			if (!player_inmap(data))
				return (0);
		}
		else
		{
			if (!is_map_closed(&map[i])
				|| !is_more_ply(map[i], data))
				return (0);
		}
	}
	if (!work_smart(map, data))
		return (0);
	return (1);
}

int	ft_parse_map(char **content, t_p *data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	if (!go_through_map(content, data, &i, &c))
		return (0);
	if (!content[i])
		return (map_error(3));
	while (content[i] && !is_valid_map(content[i]))
		i++;
	if (!content[i])
		return (map_error(4));
	if (!map_validity(&content[i], data))
		return (map_error(4));
	while (content[i + 1] && is_valid_map(content[i + 1]))
		i++;
	free_content(data->content);
	return (1);
}
