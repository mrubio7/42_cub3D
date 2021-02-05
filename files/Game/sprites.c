/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:06:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/05 19:15:21 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		init_sprites(t_all *all)
{
	all->spos = malloc(sizeof(t_spos) * 5);
	
	all->spos[0].x = 1.5;
	all->spos[0].y = 1.5;
	all->spos[0].tex = 2;
	all->spos[1].x = 3.5;
	all->spos[1].y = 1.5;
	all->spos[1].tex = 2;
	all->spos[2].x = 10.5;
	all->spos[2].y = 2.5;
	all->spos[2].tex = 2;
	all->spos[3].x = 12.5;
	all->spos[3].y = 3.5;
	all->spos[3].tex = 2;
	all->spos[4].x = 13.5;
	all->spos[4].y = 2.5;
	all->spos[4].tex = 2;
}

void		sprite_order(t_all *all)
{
	int x;

	x = 0;
	all->spr.sp_ord = malloc(numSprites * sizeof(int));
	all->spr.sp_dis = malloc(numSprites * sizeof(double));
	while (x < numSprites)
	{
		all->spr.sp_ord[x] = x;
		all->spr.sp_dis[x] = ((all->pj.posX - all->spos[x].x) * (all->pj.posX - all->spos[x].x) + (all->pj.posY - all->spos[x].y) * (all->pj.posY - all->spos[x].y));
		x++;
	}
	ft_sort_index(all->spr.sp_dis, all->spr.sp_ord, numSprites);
}

void		sprite_calc_stripe(t_all *all)
{
	int x;
	int y;
	int d;

	x = all->spr.drawStX;
	y = all->spr.drawStY;
	while (x < all->spr.drawEnX)
	{
		all->wtex.texX = (int)(256 * (x - (-all->spr.spW / 2 + all->spr.sp_screenX)) * all->wtex.texW / all->spr.spW) / 256;
		if (all->spr.transformY > 0 && x < all->map.resW && all->spr.transformY < all->spr.zbuffer[x])
		{
			while (y < all->spr.drawEnY)
			{
				d = (y) * 256 - all->map.resH * 128 + all->spr.spH * 128;
				all->wtex.texY = ((d * all->wtex.texH) / all->spr.spH) / 256;
				all->game.color = get_color_from_addr(all, 4);
				if ((all->game.color & 0x00FFFFFF) != 0)
					all->spr.buff[y][x] = all->game.color;
				y++;
			}
		}
		x++;
	}
	
}

void		sprite_pos(t_all *all)
{
	int x;

	x = 0;
	while (x < numSprites)
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
		x++;
	}
}

void		get_sprites(t_all *all, int z)
{
	init_sprites(all);
	all->spr.buff = malloc(all->map.resH * all->map.resW * sizeof(int));
	sprite_order(all);
	sprite_pos(all);
	sprite_calc_stripe(all);
	draw_sprite(all);
}
