/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:23:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:53:55 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		free_game(t_all *all)
{
	int	y;

	y = 0;
	while (all->map.map[y])
		free(all->map.map[y++]);
	free(all->map.path_n);
	free(all->map.path_s);
	free(all->map.path_e);
	free(all->map.path_w);
	free(all->map.path_i);
	free(all->map.map);
	free(all->spos);
	free(all->spr.zbuffer);
	free(all->spr.sp_ord);
	free(all->spr.sp_dis);
}

int			close_game_x(t_all *all)
{
	free_game(all);
	exit(0);
	return (0);
}

int			close_game(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		free_game(all);
		exit(0);
	}
	return (0);
}

int			init_game(t_all *all)
{
	all->pj = detect_start_pos(all->map.map, all->pj);
	all->vars.win = mlx_new_window(all->vars.mlx, all->map.resw,\
					all->map.resh, "cub3D");
	all->img.img = mlx_new_image(all->vars.mlx, all->map.resw, all->map.resh);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,\
					&all->img.line_length, &all->img.endian);
	mlx_key_hook(all->vars.win, close_game, all);
	mlx_hook(all->vars.win, 17, 131072L, close_game_x, all);
	mlx_hook(all->vars.win, 2, 1L << 0, movement_pj, all);
	all->spr.zbuffer = malloc(all->map.resw * sizeof(int));
	all->spr.sp_ord = malloc(NUMSPRITES * sizeof(int));
	all->spr.sp_dis = malloc(NUMSPRITES * sizeof(double));
	if (load_textures(all) == -1)
	{
		perror("ERROR\nError loading textures");
		return (0);
	}
	init_sprites(all);
	if (all->vars.bmp == 1)
		save_bmp(all);
	mlx_loop_hook(all->vars.mlx, loop_frame, all);
	mlx_loop(all->vars.mlx);
	return (1);
}
