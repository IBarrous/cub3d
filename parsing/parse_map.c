/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:51:57 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 05:54:47 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	go_through_map(char **content, t_p *data, int *i, int *c)
{
	init_txt(data);
	while (content[(*i)] && *c < 6)
	{
		if (!check_txt(content, data, i, c)
			|| !check_colors(content, data, i, c))
			return (0);
		if (!is_valid_ch(content, i))
			return (map_error(2));
		if (content[(*i)][0] == '\0')
				(*i)++;
	}
	return (1);
}

void	check_extension(char *map)
{
	int		i;
	int		j;
	char	*to_cmp;

	i = 0;
	j = 0;
	to_cmp = "buc."; // ".cub"
	while (map[i])
		i++;
	i--;
	while (to_cmp[j])
	{
		printf("%c %c\n", to_cmp[j], map[i]);
		if (to_cmp[j++] != map[i--])
			break ;
	}
	map_error(1);
	exit (0);
}

void	free_texture(char **txt)
{
	if (*txt)
	{
		free(*txt);
		txt = 0;
	}
}

void	free_all_textures(t_p *data)
{
	free_texture(&data->n);
	free_texture(&data->s);
	free_texture(&data->e);
	free_texture(&data->w);
}

t_p	map_parse(char **av)
{
	int	fd;
	int	flag_error;
	t_p	data;
	//check_extension(av[1]);
	init_all(&data);
	flag_error = 1;
	fd = open (av[1], O_RDONLY);
	if (fd <= 0)
	{
		write(2, "\033[1;31mError: Invalid file\n", 28);
		exit(1);
	}
	flag_error = extract_content(&data, fd);
	if (!flag_error)
	{
		write(2, "\033[1;31mError: can't extract map\n", 33);
		exit(1);
	}
	if (!ft_parse_map(data.content, &data))
	{
		free_content(data.content);
		free_all_textures(&data);
		exit(1);
	}
	return (data);
}
