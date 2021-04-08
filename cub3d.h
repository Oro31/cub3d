/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:56:50 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 11:10:05 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}

typedef	struct	s_sprt
{
	char	**path;
	void	**img;
}			t_sprite;

typedef	struct	s_rsl
{
	int		w;
	int		h;
}			t_resol;

typedef	struct	s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}			t_rgb;

typedef	struct	s_cam
{
	int		posx;
	int		posy;
	int		dir;
}			t_cam;

typedef	struct	s_map
{
	int		**box;
	t_cam	cam;
}			t_map;

char	*ft_parse_path(char *line, int iswall);
int		ft_parse_tex(char *line, char **tpath);

void	ft_parse_rsl(char *line, int *width, int *height);

void	ft_rgb_fill(t_rgb *rgb, char *line);

int		ft_rgbtocolor(uint8_t r, uint8_t g, uint8_t b);
t_rgb	*ft_colortorgb(int color);

void	ft_mymlx_pixelput(t_data *data, int skycolor, int groundcolor);

int		ft_istex_line(char *line);
int		ft_isrgb_line(char *line);
int		ft_ismap_line(char *line);
int		ft_check_line(char *line);

int		ft_ismap_member(char c);
int		ft_len_mpline(char *line);
char	*ft_linemap_realloc(char **map, int i);
char	*ft_linemap_fill(char *line, int maxlen);
char	**ft_parse_map(char *line, char **map);

int		ft_lenmax_mpline(char **map);
int		ft_is_space_diagwalled_tool(char **map, int i, int j, int len);
int		ft_is_space_diagwalled(char **map, int i, int j, int len);
int		ft_is_space_walled(char**map, int i, int j, int len);
int		ft_ismap_walled(char **map);

int		ft_isdigit(int c);

#endif
