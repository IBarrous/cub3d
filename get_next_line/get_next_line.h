/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:39:54 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:22:26 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

size_t	ft_strle(char *str);
char	*ft_strch(char *str, int c);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_remain_str(char *remain_str);
char	*ft_extract_line(char *str);
char	*get_next_line(int fd);
char	*ft_read_and_join(int fd, char *str);
#endif
