/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 23:20:37 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int		close_game_x(int keycode, t_vars *vars)
{
	exit(0);
	return (0);
}

int		close_game_esc(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (1);
}

int		init_game(t_all all)
{
	all.pj = detect_start_pos(all.map.map, all.pj);
	all.vars.win = mlx_new_window(all.vars.mlx, all.map.res_width, all.map.res_heigth, "cub3D");
	all.img.img = mlx_new_image(all.vars.mlx, all.map.res_width, all.map.res_heigth);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel, 
								&all.img.line_length, &all.img.endian);
	mlx_hook(all.vars.win, 17, 1L<<17, close_game_x, &all.vars);
	mlx_key_hook(all.vars.win, close_game_esc, &all.vars);
	mlx_hook(all.vars.win, 2, 1L<<0, movement_pj, &all.pj);
	loop_frame(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_loop_hook(all.vars.mlx, loop_frame, &all);
	mlx_loop(all.vars.mlx);
	return (0);
}
