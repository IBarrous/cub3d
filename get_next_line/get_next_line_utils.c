/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:28:17 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:20:56 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strle(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strch(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (s + i);
	else
		return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*new_s;
	int		i;
	int		j;

	if (str == NULL)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	if (str == NULL || buffer == NULL)
		return (0);
	i = -1;
	new_s = malloc(ft_strle(str) + ft_strle(buffer) + 1);
	if (new_s == NULL)
		return (NULL);
	while (str[++i] != '\0')
		new_s[i] = str[i];
	j = -1;
	while (buffer[++j] != '\0')
		new_s[i++] = buffer[j];
	new_s[i] = '\0';
	free (str);
	return (new_s);
}

char	*ft_extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (line);
}

char	*ft_remain_str(char *remain_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remain_str[i] != '\0' && remain_str[i] != '\n')
		i++;
	if (remain_str[i] == '\0')
	{
		free (remain_str);
		return (NULL);
	}
	str = malloc (ft_strle(remain_str) - i + 1);
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (remain_str[i] != '\0')
		str[j++] = remain_str[i++];
	str[j] = '\0';
	free(remain_str);
	return (str);
}
