/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/13 20:38:11 by mrubio           ###   ########.fr       */
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
		preparing_dda(&ray, &pj);
		
	}
	mlx_loop(vars->mlx);
	return (0);
}