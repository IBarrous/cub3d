/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:55:39 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/10 01:55:39 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../cub3d.h"

int	check_tmp(t_p *data, char **t)
{
	if (!t)
	{
		free_content(data->content);
		return (0);
	}
	return (1);
}

int	work_smart(char **map, t_p *data)
{
	char	**tmp;
	int		i;

	i = -1;
	while (map[++i])
	tmp = malloc((i + 2) * sizeof(char *));
	if (!check_tmp(data, tmp))
		return (0);
	i = 0;
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		if (!tmp[i])
		{
			free_content(data->content);
			free_s(&tmp, i - 1);
			return (0);
		}
		i++;
	}
	tmp[i] = NULL;
	data->map_cont = tmp;
	if (!look_for_dir(data->map_cont) || !check_chars(data->map_cont))
		return (0);
	return (1);
}

int	conv_to_space(t_p *data)
{
	int	i;
	int	tab_count;

	i = 0;
	while (data->content[i])
	{
		if (ft_strchr(data->content[i], '\t'))
		{
			tab_count = count_c(data->content[i], '\t');
			data->content[i] = realoc_tab(data->content[i], tab_count);
			if (!data->content[i])
			{
				free_s(&data->content, i - 1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_new_line(t_p *data)
{
	char	**s;
	int		i;

	i = 0;
	(data->count_line)++;
	s = malloc(((data->count_line) + 2) * sizeof(char *));
	if (!s)
	{
		free_content(data->content);
		return (0);
	}	
	while (data->content[i])
	{
		s[i] = data->content[i];
		i++;
	}
	s[data->count_line] = 0;
	s[data->count_line + 1] = 0;
	free(data->content);
	data->content = s;
	return (1);
}

int	extract_content(t_p *data, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->content[data->count_line] = line;
		if (!ft_new_line(data))
			return (error_pars());
	}
	if (!conv_to_space(data))
		return (error_pars());
	if (!line)
		free(line);
	return (1);
}
