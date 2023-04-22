/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:01:17 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/10 03:01:17 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*free_content(char **content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
	return (0);
}

void	free_matrix(char **s)
{
	while (*s)
	{
		free(*s);
		s++;
	}
}

int	is_more_ply(char *s, t_p *data)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr("NSEW", s[i]))
		{
			if (!data->ply_pos)
				data->ply_pos = s[i];
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_all_sides(char **s, int col)
{
	if (ft_isspace(s[-1][col - 1]) || !s[-1][col - 1])
		return (0);
	if (ft_isspace(s[-1][col]) || !s[-1][col])
		return (0);
	if (ft_isspace(s[-1][col + 1]) || !s[-1][col + 1])
		return (0);
	if (ft_isspace(s[0][col - 1]) || !s[0][col - 1])
		return (0);
	if (ft_isspace(s[0][col + 1]) || !s[0][col + 1])
		return (0);
	if (ft_isspace(s[1][col - 1]) || !s[1][col - 1])
		return (0);
	if (ft_isspace(s[1][col]) || !s[1][col])
		return (0);
	if (ft_isspace(s[1][col + 1]) || !s[1][col + 1])
		return (0);
	return (1);
}

int	is_valid_ch(char **check, int *i)
{
	if (check[(*i)][0] == 'N' && check[(*i)][1] == 'O')
		return (1);
	if (check[(*i)][0] == 'S' && check[(*i)][1] == 'O')
		return (1);
	if (check[(*i)][0] == 'W' && check[(*i)][1] == 'E')
		return (1);
	if (check[(*i)][0] == 'E' && check[(*i)][1] == 'A')
		return (1);
	if (check[(*i)][0] == 'F')
		return (1);
	if (check[(*i)][0] == 'C')
		return (1);
	if (check[(*i)][0] == '\0')
		return (1);
	if (check[(*i)] == NULL)
		return (1);
	return (0);
}
