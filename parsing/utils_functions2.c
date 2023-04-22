/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:14:15 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:10:20 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if ((!dst && dstsize == 0) || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0' && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return (str + i);
	else
		return (0);
}

void	free_s(char ***s, int prev)
{
	if (prev < 0)
	{
		free(*s);
		return ;
	}
	while (prev >= 0)
	{
		free(s[0][prev]);
		s[0][prev] = 0;
		prev--;
	}
	free(*s);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	char	*s_dest;
	char	*cast;
	size_t	len;

	cast = (char *)s1;
	len = ft_strlen(cast);
	dest = (char *)malloc((len + 1) * sizeof(char));
	s_dest = dest;
	if (s_dest == 0)
		return (0);
	while (*cast != '\0')
	{
		*s_dest = *cast;
		cast++;
		s_dest++;
	}
	*s_dest = '\0';
	return (dest);
}
