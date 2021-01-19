/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 21:35:41 by mrubio           ###   ########.fr       */
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

int		init_game(t_map map, t_vars vars)
{
	t_pj	pj;
	t_img	img;

	pj = detect_start_pos(map.map, pj);
	vars.win = mlx_new_window(vars.mlx, map.res_width, map.res_heigth, "cub3D");
	img.img = mlx_new_image(vars.mlx, map.res_width, map.res_heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
								&img.line_length, &img.endian);
	mlx_hook(vars.win, 17, 1L<<17, close_game_x, &vars);
	mlx_key_hook(vars.win, close_game_esc, &vars);
	loop_frame(&vars, &map, &pj, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, movement_pj, &pj);
	//mlx_loop_hook(vars->mlx, loop_frame, pj);
	mlx_loop(vars.mlx);
	return (0);
}
