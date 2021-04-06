/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int		fd;
	char	*line;
	char	**texpath;
	char	**map;
	t_rgb	ground;
	t_rgb	sky;
	int		fstdmsz;
	int		w;
	int		h;
	int		i;
	int		j;

	printf("start \n");
	w = 0;
	h = 0;
	fstdmsz = 1;
	if (!(map = malloc(sizeof(char*))))
		return (0);
	map[0] = NULL;
	if (!(texpath = malloc(sizeof(char*) * 6)))
		return (0);
	texpath[5] = NULL;
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == 2)
		{
			j = ft_parse_tex(line, texpath);
			if (j == 1)
				printf("parse tex : SUCCES \n");
		}
		else if (ft_check_line(line) == 1)
		{
			ft_parse_rsl(line, &w, &h);
			printf("w = %d, h = %d \n", w, h);
		}
		else if (ft_check_line(line) == 3)
		{
			if (line[0] == 'F')
				ft_rgb_fill(&ground, line);
			else
				ft_rgb_fill(&sky, line);
			printf ("ground rgb = %u,%u,%u \n", ground.r, ground.g, ground.b);
			printf ("sky rgb = %u,%u,%u \n", sky.r, sky.g, sky.b);
		}
		else if (ft_check_line(line) == 4)
		{
			printf("before parse map \n");
			map = ft_parse_map(line, map);
		}
		/*if (ft_parse(line) != 1)
			return (0);*/
		/*if (!(map = ft_firstdim_mapalloc(line, map, fstdmsz)))
			return (0);
		fstdmsz++;*/
	}
	printf("is map walled ? %d \n", ft_ismap_walled(map));
	i = 0;
	while (texpath[i])
	{
		printf("texpath[%d] = %s \n", i, texpath[i]);
		free(texpath[i]);
		i++;
	}
	free(texpath);
	i = 0;
	while(map[i])
	{
		printf("map[%d] = %s \n", i , map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
	return (0);
}
