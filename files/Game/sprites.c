/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:06:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 08:26:11 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		sprite_pos(t_all *all, int x)
{

	all->spr.spX = all->spos[all->spr.sp_ord[x]].x - all->pj.posX;
	all->spr.spY = all->spos[all->spr.sp_ord[x]].y - all->pj.posY;
	all->spr.invDet = 1.0 / (all->pj.planeX * all->pj.dirY - all->pj.dirX * all->pj.planeY);
	all->spr.transformX = all->spr.invDet * (all->pj.dirY * all->spr.spX - all->pj.dirX * all->spr.spY);
	all->spr.transformY = all->spr.invDet * (-all->pj.planeY * all->spr.spX + all->pj.planeX * all->spr.spY);
	all->spr.sp_screenX = (int)((all->map.resW / 2) * (1 + all->spr.transformX / all->spr.transformY));
	all->spr.spH = ft_abs((int)(all->map.resH / (all->spr.transformY)));
	all->spr.drawStY = -all->spr.spH / 2 + all->map.resH / 2;
	all->spr.drawStY = (all->spr.drawStY < 0) ? 0 : all->spr.drawStY;
	all->spr.drawEnY = all->spr.spH / 2 + all->map.resH / 2;
	all->spr.drawEnY = (all->spr.drawEnY >= all->map.resH) ? all->map.resH - 1 : all->spr.drawEnY;
	all->spr.spW = ft_abs((int)(all->map.resH / (all->spr.transformY)));
	all->spr.drawStX = -all->spr.spW / 2 + all->spr.sp_screenX;
	all->spr.drawStX = (all->spr.drawStX < 0) ? 0 : all->spr.drawStX;
	all->spr.drawEnX = all->spr.spW / 2 + all->spr.sp_screenX;
	all->spr.drawEnX = (all->spr.drawEnX >= all->map.resW) ? all->map.resW - 1 : all->spr.drawEnX;
}

void		sprite_calc_stripe(t_all *all, int z)
{
	int y;
	int d;
	int i;

	i = 0;
	y = all->spr.drawStY;
	all->wtex.texX = (int)(256 * (z - (-all->spr.spW / 2 + all->spr.sp_screenX)) * all->wtex.texW / all->spr.spW) / 256;
	if (all->spr.transformY > 0 && z < all->map.resW && all->spr.transformY < all->spr.zbuffer[z] && z > all->spr.drawStX && z < all->spr.drawEnX)
	{
		while (y < all->spr.drawEnY)
		{
			d = (y) * 256 - all->map.resH * 128 + all->spr.spH * 128;
			all->wtex.texY = ((d * all->wtex.texH) / all->spr.spH) / 256;
			all->game.color = get_color_from_addr(all, 4);
			if ((all->game.color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(&all->img, all->map.resW - z, y, all->game.color);
			i++;
			y++;
		}
	}
}

void		get_sprites(t_all *all, int z)
{
	int p;

	p = 0;
	while (p <= 3)
	{
		all->spr.sp_ord[p] = p;
		all->spr.sp_dis[p] = ((all->pj.posX - all->spos[p].x) * (all->pj.posX - all->spos[p].x) + (all->pj.posY - all->spos[p].y) * (all->pj.posY - all->spos[p].y));
		sprite_pos(all, p);
		sprite_calc_stripe(all, z);
		p++;
	}
}
