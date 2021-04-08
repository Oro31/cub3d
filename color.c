/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 10:46:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_rgbtocolor(uint8_t r, uint8_t g, uint8_t b)
{
	int		res;

	printf("encode rgb : first methode = %d \n", 65536 * r + 256 * g + b);
	res = (r << 16 | g << 8 | b);
	return (res);
}

t_rgb	*ft_colortorgb(int color)
{
	t_rgb	*rgb;

	rgb->r = (color << 16) & 0xFF;
	rgb->g = (color << 8) & 0xFF;
	rgb->b= color & 0xFF;
	return (rgb);
}
