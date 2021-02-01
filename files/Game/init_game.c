/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/31 22:16:55 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_game(t_all *all)
{
	int y;

	y = 0;
	while (all->map.map[y])
	{
		free(all->map.map[y]);
		y++;
	}
	free(all->map.path_N);
	free(all->map.path_S);
	free(all->map.path_E);
	free(all->map.path_W);
	free(all->map.path_I);
	free(all->map.map);
}

int		close_game_x(int keycode, t_all *all)
{
	free_game(all);
	exit(0);
	return (0);
}

int		close_game_esc(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		free_game(all);
		exit(0);
	}
	return (1);
}

int		init_game(t_all all)
{
	all.pj = detect_start_pos(all.map.map, all.pj);
	all.vars.win = mlx_new_window(all.vars.mlx, all.map.resW, all.map.resH, "cub3D");
	all.img.img = mlx_new_image(all.vars.mlx, all.map.resW, all.map.resH);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel, 
								&all.img.line_length, &all.img.endian);
	mlx_hook(all.vars.win, 17, 1L<<17, close_game_x, &all.vars);
	mlx_key_hook(all.vars.win, close_game_esc, &all.vars);
	mlx_hook(all.vars.win, 2, 1L<<0, movement_pj, &all);
	if (load_textures(&all) == -1)
	{
		ft_printf("ERROR LOADING TEXTURES\n");
		return (0);
	}
	loop_frame(&all);
	mlx_loop_hook(all.vars.mlx, loop_frame, &all);
	mlx_loop(all.vars.mlx);
	return (1);
}
