/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/14 22:45:09 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_game(t_map map, t_vars vars)
{
	t_pj	pj;
	t_ray	ray;
	t_game	game;
	t_img	img;

	pj = detect_start_pos(map.map, pj);
	vars.win = mlx_new_window(vars.mlx, map.res_width, map.res_heigth, "cub3D");
	loop_frame(&vars, &map, pj, ray, game, &img);
	return (0);
}