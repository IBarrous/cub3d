/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 05:40:41 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 05:53:35 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_bleu_fl(char *check, t_p *data, int i)
{
	if (check[i++] != ',')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->blue_fl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	if (check[i] != '\0')
		return (error_colors(4));
	return (1);
}

int	check_bleu_cl(char *check, t_p *data, int i)
{
	if (check[i++] != ',')
		return (0);
	if (!ft_isdigit(check[i]))
		return (0);
	data->blue_cl = ft_atoi(&check[i]);
	while (ft_isdigit(check[i]))
		i++;
	if (check[i] != '\0')
		return (error_colors(5));
	return (1);
}
