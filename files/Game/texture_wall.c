/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:07:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/25 18:51:52 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			get_texture_wall(t_all *all)
{
	int y;
	int z;

	z = 0;
	y = all->game.drawSt;
	all->wtex.buff = malloc(all->map.resH * sizeof(int));
	while (y < all->game.drawEn)
	{
		all->wtex.texY = (int)all->wtex.texPos & (all->wtex.texH - 1);
		all->wtex.texPos += all->wtex.texStep;
		all->wtex.color = all->wtex.texture[all->wtex.texNum][all->wtex.texW * all->wtex.texY + all->wtex.texX];
		if (all->ray.side == 1)
			all->wtex.color = (all->wtex.color >> 1) & 8355711;
		all->wtex.buff[z++] = all->wtex.color;
		y++;
	}
}

void		calc_draw_texture(t_all *all)
{
	all->wtex.texStep = 1.0 * all->wtex.texH / all->game.lineH;
	all->wtex.texPos = (all->game.drawSt - all->map.resH / 2 + all->game.lineH / 2) * all->wtex.texStep;
	
}

void		pos_wall_texture(t_all *all)
{
	if (all->ray.side == 0)
		all->wtex.wallX = all->pj.posY + all->game.perpWallDist * all->ray.rayDirY;
	else
		all->wtex.wallX = all->pj.posX + all->game.perpWallDist * all->ray.rayDirX;
//all->wtex.wallX -= floor((all->wtex.wallX));??????????????????
	all->wtex.texX = (all->wtex.wallX * (double)all->wtex.texW);
	if (all->ray.side == 0 && all->ray.rayDirX > 0)
		all->wtex.texX = all->wtex.texW - all->wtex.texX - 1;
	if (all->ray.side == 1 && all->ray.rayDirY < 0)
		all->wtex.texX = all->wtex.texW - all->wtex.texX - 1;

}

void		texture_line(t_all *all)
{
	all->wtex.texNum = all->map.map[all->ray.mapY][all->ray.mapX];
	pos_wall_texture(all);
	calc_draw_texture(all);
	get_texture_wall(all);
}