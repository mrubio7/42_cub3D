/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/14 22:39:19 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_vars *vars, t_map *map, t_pj pj, t_ray ray, t_game game, t_img *img)
{
	int z;

	z = 0;
	img->img = mlx_new_image(vars->mlx, map->res_width, map->res_heigth);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, 
								&img->line_length, &img->endian);
	while (z++ < map->res_width)
	{
		pj.cameraX = 2 * z / map->res_width - 1;
		ray.rayDirX = pj.dirX + pj.planeX * pj.cameraX;
		ray.rayDirY = pj.dirY + pj.planeY * pj.cameraX;
		v_line(vars, &ray, &pj, &game, map, img, z);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
	return (0);
}