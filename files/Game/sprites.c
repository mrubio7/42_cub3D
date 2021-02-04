/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:06:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/04 18:20:53 by mrubio           ###   ########.fr       */
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

void		sortSprites(t_all *all)
{
	int x;
	int c;

	x = 0;
	c = 0;
	while (x <= numSprites)
	{
		all->spr.sp_ord[c] = 0;
		if (all->spr.sp_dis[c] <= all->spr.sp_dis[x])
			all->spr.sp_ord[c++]++;
		if (x == numSprites)
			x = 0;
		x++;
	}
	while (x <= numSprites)
	{
		if (all->spr.sp_ord[c] == all->spr.sp_ord[x])
			all->spr.sp_ord[c++]++;
		if (x == numSprites)
			x = 0;
		x++;
	}
}

void		sprite_order(t_all *all)
{
	int x;

	x = 0;
	all->spr.sp_ord = malloc(numSprites * sizeof(int));
	all->spr.sp_dis = malloc(numSprites * sizeof(double));
	while (x < numSprites)
	{
		all->spr.sp_dis[x] = ((all->pj.posX - all->spos[x].x) * (all->pj.posX - all->spos[x].x) + (all->pj.posY - all->spos[x].y) * (all->pj.posY - all->spos[x].y));
		x++;
	}
	sortSprites(all);
	x = 0;
	while (x < numSprites)
	
}

void		get_sprites(t_all *all, int z)
{
	init_sprites(all);
	all->spr.buff = malloc(all->map.resH * all->map.resW * sizeof(int));
	sprite_order(all);
	
}
