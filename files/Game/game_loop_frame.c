/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 08:11:57 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_all *all)
{
	int z;

	z = 0;
	all->spr.zbuffer = malloc(all->map.resW * sizeof(int));
	while (z < all->map.resW)
	{
		mlx_clear_window(all->vars.mlx, all->vars.win);
		v_line(all, z);
		all->spr.zbuffer[z] = all->game.perpWallDist;
		z++;
	}
	z = 0;
	all->spr.sp_ord = malloc(numSprites * sizeof(int));
	all->spr.sp_dis = malloc(numSprites * sizeof(double));
	ft_sort_index(all->spr.sp_dis, all->spr.sp_ord, numSprites);
	while (z++ <= all->map.resW)
		get_sprites(all, z);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	mlx_do_sync(all->vars.mlx);
	return (0);
}