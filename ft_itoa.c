/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:21 by ibarrous          #+#    #+#             */
/*   Updated: 2022/12/17 13:44:25 by ibarrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	int_len(long num)
{
	int	len;

	len = 0;
	if (!num)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*char_fill(char *str, int i, long ln)
{
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[i] = 48 + (ln % 10);
		ln /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		i;

	ln = n;
	i = int_len(ln);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (ln == 0)
	{
		str[0] = 48;
		return (str);
	}
	return (char_fill(str, i, ln));
}
