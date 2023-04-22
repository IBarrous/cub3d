/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:50:29 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:03:12 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_txt(t_p *data)
{
	data->n = 0;
	data->s = 0;
	data->e = 0;
	data->w = 0;
}

void	init_all(t_p *data)
{
	data->content = malloc(2 * sizeof(char *));
	if (!data->content)
		return ;
	data->content[0] = 0;
	data->content[1] = 0;
	data->count_cont = 0;
	data->n = 0;
	data->s = 0;
	data->w = 0;
	data->e = 0;
	data->red_fl = 0;
	data->green_fl = 0;
	data->blue_fl = 0;
	data->red_cl = 0;
	data->green_cl = 0;
	data->blue_cl = 0;
	data->ply_pos = 0;
	data->count_line = 0;
}

int	is_valid_map(char *ch)
{
	int	i;

	i = 0;
	if (ch[i] == '\0')
		return (0);
	while (ch[i])
	{
		if (!ft_isspace(ch[i]) && !ft_strchr("01NSEW", ch[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_c(char *s, char ch)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == ch)
			c++;
		i++;
	}
	return (c);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
