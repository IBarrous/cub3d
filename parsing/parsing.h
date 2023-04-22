/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-beka <ael-beka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:11:30 by ael-beka          #+#    #+#             */
/*   Updated: 2023/04/12 06:17:03 by ael-beka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"

typedef struct parsing
{
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	int		count_line;
	char	**content;
	int		red_fl;
	int		green_fl;
	int		blue_fl;
	int		red_cl;
	int		green_cl;
	int		blue_cl;
	char	ply_pos;
	int		count_cont;
	char	**map_cont;
}				t_p;

int		append(int i);
t_p		map_parse(char **av);
int		error_pars(void);
int		error_colors(int mode);
int		map_error(int mode);
int		texture_error(int mode);
int		check_cl_val(t_p *data);
int		check_fl_val(t_p *data);
int		check_cl_color(char *check, t_p *data);
int		check_fl_color(char *check, t_p *data);
int		check_colors(char	**check, t_p *data, int *i, int *c);
int		is_txt_horiz(char **txt, t_p *data, int *i, int *c);
int		is_txt_vert(char **txt, t_p *data, int *i, int *c);
int		check_txt(char	**txt, t_p *data, int *i, int *c);
int		go_through_map(char **content, t_p *data, int *i, int *c);
void	check_extension(char *map);
void	repl_tabs(char	**tmp, char **s, int len);
void	*realoc_tab(char	*s, int tab_count);
int		conv_to_space(t_p *data);
int		ft_new_line(t_p *data);
int		extract_content(t_p *data, int fd);
int		is_map_closed(char	**map);
int		player_inmap(t_p *data);
int		correct_wall(char *s);
int		map_validity(char	**map, t_p *data);
int		ft_parse_map(char **content, t_p *data);
void	init_txt(t_p *data);
void	init_all(t_p *data);
int		is_valid_map(char *ch);
int		count_c(char *s, char ch);
void	*free_content(char **content);
int		is_more_ply(char *s, t_p *data);
int		ft_all_sides(char **s, int col);
void	free_s(char ***s, int prev);
int		is_valid_ch(char **check, int *i);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
int		extract_content(t_p *data, int fd);
int		work_smart(char **map, t_p *data);
int		north_textures(char	*txt, t_p *data);
int		south_textures(char	*txt, t_p *data);
int		western_textures(char	*txt, t_p *data);
int		east_textures(char	*txt, t_p *data);
int		east_textures(char	*txt, t_p *data);
char	*ft_strdup(char *s1);
int		ft_isascii(int c);
int		check_bleu_fl(char *check, t_p *data, int i);
int		check_bleu_cl(char *check, t_p *data, int i);
int		check_chars(char **map);

#endif