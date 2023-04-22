/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:03 by ibarrous          #+#    #+#             */
/*   Updated: 2022/12/17 13:46:11 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	unb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb *= -1;
	}
	if (unb < 10)
	{
		ft_putchar_fd(unb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(unb / 10, fd);
		ft_putnbr_fd(unb % 10, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		write(fd, &s[i], 1);
}
