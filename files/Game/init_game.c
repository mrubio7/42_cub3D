/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/11 21:55:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_game(t_map map, t_vars vars)
{
	t_pj	pj;
	t_cam	cam;
	t_ray	ray;

	pj = detect_start_pos(map.map, pj);
	vars.win = mlx_new_window(vars.mlx, map.res_width, map.res_heigth, "cub3D");
	while (loop_frame(&vars, map.map, pj, cam, ray) != -1)
	{
		
	}
	return (0);
}