/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/13 21:13:00 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_vars *vars, t_map *map, t_pj pj, t_cam cam,  t_ray ray)
{
	int z;

	z = 0;
	while (z < map->res_width)
	{
		cam.cameraX = 2 * z / map->res_width - 1;
		ray.rayDirX = pj.dirX + cam.planeX * cam.cameraX;
		ray.rayDirY = pj.dirY + cam.planeY * cam.cameraX;
		dda_algorithm(&ray, &pj, map->map);
		
	}
	mlx_loop(vars->mlx);
	return (0);
}