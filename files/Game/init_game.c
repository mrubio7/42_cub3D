/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 18:45:35 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_game(t_map map, t_vars vars)
{
	t_pj	pj;
	t_game	game;
	t_img	img;

	pj = detect_start_pos(map.map, pj);
	vars.win = mlx_new_window(vars.mlx, map.res_width, map.res_heigth, "cub3D");
	img.img = mlx_new_image(vars.mlx, map.res_width, map.res_heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
								&img.line_length, &img.endian);
	loop_frame(&vars, &map, &pj, game, &img);
	return (0);
}