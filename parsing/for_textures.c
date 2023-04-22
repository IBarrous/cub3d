/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 06:35:30 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 00:00:30 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	north_textures(char	*txt, t_p *data)
{
	int	i;

	i = 2;
	while (ft_isspace(txt[i]))
		i++;
	data->n = ft_strdup(&txt[i]);
	if (!data->n)
		return (0);
	return (1);
}

int	south_textures(char	*txt, t_p *data)
{
	int	i;

	i = 2;
	while (ft_isspace(txt[i]))
		i++;
	data->s = ft_strdup(&txt[i]);
	if (!data->s)
		return (0);
	if (open(data->s, O_RDONLY) < 0)
		return (0);
	return (1);
}

int	western_textures(char	*txt, t_p *data)
{
	int	i;

	i = 2;
	while (ft_isspace(txt[i]))
		i++;
	data->w = ft_strdup(&txt[i]);
	if (!data->w)
		return (0);
	if (open(data->w, O_RDONLY) < 0)
		return (0);
	return (1);
}

int	east_textures(char	*txt, t_p *data)
{
	int	i;

	i = 2;
	while (ft_isspace(txt[i]))
		i++;
	data->e = ft_strdup(&txt[i]);
	if (!data->e)
		return (0);
	if (open(data->e, O_RDONLY) < 0)
		return (0);
	return (1);
}
