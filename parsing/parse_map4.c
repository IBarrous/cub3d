/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 06:08:00 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:08:13 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	repl_tabs(char	**tmp, char **s, int len)
{
	size_t	i;
	size_t	j;

	tmp[0][0] = '\0';
	i = 0;
	j = 0;
	while (i < ft_strlen(s[0]))
	{
		if (s[0][i] == '\t')
		{
			ft_strlcat((void *)tmp[0], "    ", len);
			j += 4;
		}
		else
		{
			tmp[0][j] = s[0][i];
			j++;
		}
		i++;
	}
	tmp[0][j] = '\0';
	free(*s);
	*s = 0;
}

void	*realoc_tab(char	*s, int tab_count)
{
	int		len;
	char	*tmp;

	len = ft_strlen(s) + (tab_count * 3);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (0);
	repl_tabs(&tmp, &s, len);
	return (tmp);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != 'E' && map[i][j] != ' ') && (map[i][j] != 'W'
					&& map[i][j] != 'S')
					&& (map[i][j] != 'N' && map[i][j] != '0')
					&& map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
