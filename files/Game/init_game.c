/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/10 20:03:17 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		init_game(t_map map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars = detect_start_pos(map.map, vars);
	vars.win = mlx_new_window(vars.mlx, map.res_width, map.res_heigth, "cub3D");
	mlx_loop(vars.mlx);
	return (0);
}