/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:09:59 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_all *all)
{
	int z;

	z = 0;
	mlx_do_sync(all->vars.mlx);
	while (z < all->map.resw)
	{
		v_line(all, z);
		all->spr.zbuffer[z] = all->game.perpwalldist + 1;
		z++;
	}
	get_sprites(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}
