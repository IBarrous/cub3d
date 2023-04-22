/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:39:29 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 05:37:49 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_join(int fd, char *str)
{
	char	*buffer;
	int		n_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	n_bytes = 1;
	while (!ft_strch(str, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_and_join(fd, str);
	if (!str)
		return (NULL);
	line = ft_extract_line(str);
	str = ft_remain_str(str);
	return (line);
}
