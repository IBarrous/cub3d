/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:48:46 by ibarrous          #+#    #+#             */
/*   Updated: 2023/04/12 01:18:52 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_sep(char sep, char c)
{
	if (sep == c)
		return (1);
	return (0);
}

static int	count_strings(const char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*str)
	{
		while (*str && check_sep(sep, *str))
			str++;
		if (*str)
			count++;
		while (*str && !check_sep(sep, *str))
			str++;
	}
	return (count);
}

static char	*word_alloc(const char *str, char sep)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	while (str[i] != '\0' && !check_sep(sep, str[i]))
		i++;
	len = i;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_free(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**strings;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (NULL);
	while (*str)
	{
		while (*str && check_sep(c, *str))
			str++;
		if (*str)
		{
			strings[i] = word_alloc(str, c);
			if (!strings[i])
				return (ft_free(strings));
			i++;
		}
		while (*str && !check_sep(c, *str))
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
