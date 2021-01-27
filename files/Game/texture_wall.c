/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:07:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/27 23:27:34 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		calc_pos_wall_hit(t_all *all)
{
	if (all->ray.side == 0)
		all->wtex.wallX = all->pj.posY + all->game.perpWallDist * all->ray.rayDirY;
	else
		all->wtex.wallX = all->pj.posX + all->game.perpWallDist * all->ray.rayDirX;
	all->wtex.wallX -= floor((all->wtex.wallX));
	all->wtex.texX = (all->wtex.wallX * (double)all->wtex.texW);
	if (all->ray.side == 0 && all->ray.rayDirX > 0)
		all->wtex.texX = all->wtex.texW - all->wtex.texX - 1;
	if (all->ray.side == 1 && all->ray.rayDirX < 0)
		all->wtex.texX = all->wtex.texW - all->wtex.texX - 1;
}

void		calc_pos_tex_to_wall(t_all *all)
{
	int y;
	int i;

	all->wtex.buff = (int *)malloc(all->game.lineH * sizeof(int *));
	i = 0;
	y = all->game.drawSt;
	all->wtex.texPos = (all->game.drawSt - all->map.resH / 2 + all->game.lineH / 2) * all->wtex.texStep;
	while (y < all->game.drawEn)
	{
		all->wtex.texY = (int)all->wtex.texPos & (all->wtex.texH - 1);
		all->wtex.texPos += all->wtex.texStep;
		all->game.color = all->tximg[all->wtex.texNum].tx_addr[all->wtex.texW * all->wtex.texY + all->wtex.texX];/////No entra
		if (all->ray.side == 1)
			all->game.color = (all->game.color >> 1) & 8355711;
		all->wtex.buff[i] = all->game.color;
		i++;
		y++;
	}
	i = 0;
	while (i < all->map.resH)
	{
		all->wtex.buff[i] = 0;
		i++;
	}
}

void		texture_line(t_all *all)
{
	all->wtex.texNum = all->map.map[all->ray.mapY][all->ray.mapX] - 49;
	all->wtex.texH = all->tximg[all->wtex.texNum].height;
	all->wtex.texW = all->tximg[all->wtex.texNum].width;
	calc_pos_wall_hit(all);
	all->wtex.texStep = 1.0 * all->wtex.texH / all->game.lineH;
	calc_pos_tex_to_wall(all);
}