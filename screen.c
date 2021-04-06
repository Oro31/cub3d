/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 08:09:32 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/05 11:15:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_rsl(char *line, int *width, int *height)
{
	int		i;
	int		r;

	r = 0;
	i = 2;
	while (line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		r = r * 10 + (line[i] - 48);
		i++;
	}
	*width = r;
	r = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		r = r * 10 + (line[i] - 48);
		i++;
	}
	*height = r;
}
