/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_all *vars)
{
	/*vars->img.img = mlx_new_image(vars->mlx, vars->rsl.w, vars->rsl.h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, 
			&vars->img.ll, &vars->img.e);
	ft_mymlx_pixelput(vars, &vars->img);*/
	mlx_put_image_to_window(vars->mlx, vars->win, vars->spr.data[3].img, 0, 0);
}
