/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:06:20 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/02 23:13:27 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		draw_sprite(t_all *all, int z)
{
	
}

void		calc_sprite(t_all *all, int z)
{
	all->spr->invDet = 1.0 / (all->pj.planeX * all->pj.dirY - all->pj.dirX * all->pj.planeY);
	all->spr->transformX = all->spr->invDet * (all->pj.dirY * all->spr->spX - all->pj.dirX * all->spr->spY);
	all->spr->transformY = all->spr->invDet * (-all->pj.planeY * all->spr->spX + all->pj.planeX * all->spr->spY);
	all->spr->sp_screenX = ((int)(all->map.resW / 2) * 1 + all->spr->transformX / all->spr->transformY);
	all->spr->spH = abs((int)all->map.resH / (all->spr->transformY));
	all->spr->drawStY = -all->spr->spH / 2 + all->map.resH / 2;
	if (all->spr->drawStY < 0)
		all->spr->drawStY = 0;
	all->spr->drawEnY = all->spr->spH / 2 + all->map.resH / 2;
	if (all->spr->drawEnY < 0)
		all->spr->drawEnY = all->map.resH - 1;
}

void		get_sprites(t_all *all, int z)
{
	int i;

	i = 0;
	all->spr->sp_dis[i] = ((all->pj.posX - sprites[i].x) * (all->pj.posX - sprites[i].x) + (all->pj.posY - sprites[i].y) * (all->pj.posY - sprites[i].y));
	while (i < numSprites)
	{
		all->spr->spX = sprites[i].x - all->pj.posX;
		all->spr->spY = sprites[i].y - all->pj.posY;
		i++;
	}
	calc_sprite(all, z);
	draw_sprite(all, z);

}
