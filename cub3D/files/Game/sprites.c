/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:06:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:11:25 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		sprite_pos(t_all *all, int x)
{
	all->spr.spx = all->spos[all->spr.sp_ord[x]].x - all->pj.posx;
	all->spr.spy = all->spos[all->spr.sp_ord[x]].y - all->pj.posy;
	all->spr.invdet = 1.0 / (all->pj.planex * all->pj.diry - \
					all->pj.dirx * all->pj.planey);
	all->spr.transformx = all->spr.invdet * (all->pj.diry * all->spr.spx - \
						all->pj.dirx * all->spr.spy);
	all->spr.transformy = all->spr.invdet * (-all->pj.planey * all->spr.spx + \
						all->pj.planex * all->spr.spy);
	all->spr.sp_screenx = (int)((all->map.resw / 2) * \
						(1 + all->spr.transformx / all->spr.transformy));
	all->spr.sph = ft_abs((int)(all->map.resh / (all->spr.transformy)));
	all->spr.drawsty = -all->spr.sph / 2 + all->map.resh / 2;
	all->spr.drawsty = (all->spr.drawsty < 0) ? 0 : all->spr.drawsty;
	all->spr.draweny = all->spr.sph / 2 + all->map.resh / 2;
	all->spr.draweny = (all->spr.draweny >= all->map.resh) ? \
					all->map.resh - 1 : all->spr.draweny;
	all->spr.spw = ft_abs((int)(all->map.resh / (all->spr.transformy)));
	all->spr.drawstx = -all->spr.spw / 2 + all->spr.sp_screenx;
	all->spr.drawstx = (all->spr.drawstx < 0) ? 0 : all->spr.drawstx;
	all->spr.drawenx = all->spr.spw / 2 + all->spr.sp_screenx;
	all->spr.drawenx = (all->spr.drawenx >= all->map.resw) ? \
					all->map.resw - 1 : all->spr.drawenx;
}

void		sprite_calc_stripe(t_all *all)
{
	int d;
	int y;

	while (all->spr.drawstx <= all->spr.drawenx)
	{
		y = all->spr.drawsty;
		all->wtex.texx = (int)(256 * (all->spr.drawstx - (-all->spr.spw / 2 + \
		all->spr.sp_screenx)) * all->wtex.texw / -all->spr.spw) / 256;
		if (all->spr.transformy > 0 && all->spr.drawstx <= all->map.resw &&\
			all->spr.transformy < all->spr.zbuffer[all->spr.drawstx])
		{
			while (y < all->spr.draweny)
			{
				d = (y) * 256 - all->map.resh * 128 + all->spr.sph * 128;
				all->wtex.texy = ((d * all->wtex.texh) /\
								all->spr.sph) / 256 + 1;
				all->game.color = get_color_from_addr(all, 4);
				if ((all->game.color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&all->img, all->map.resw - \
									all->spr.drawstx, y, all->game.color);
				y++;
			}
		}
		all->spr.drawstx++;
	}
}

void		get_sprites(t_all *all)
{
	int p;

	p = 0;
	ft_sort_index(all->spr.sp_dis, all->spr.sp_ord, NUMSPRITES);
	while (p <= NUMSPRITES)
	{
		all->spr.sp_dis[p] = ((all->pj.posx - all->spos[p].x) *\
							(all->pj.posx - all->spos[p].x) + all->pj.posy -\
							all->spos[p].y) * (all->pj.posy - all->spos[p].y);
		if ((all->spr.sp_dis[p] / 1) > 0.5)
			all->spr.sp_dis[p] = 0.5;
		sprite_pos(all, p);
		sprite_calc_stripe(all);
		p++;
	}
}
