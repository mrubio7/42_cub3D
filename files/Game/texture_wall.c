/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:07:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/30 14:31:09 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			get_color_from_addr(t_all *all)
{
	int				index;
	unsigned int	color;
	int				octets;
	int				i;

	color = 0;
	i = -1;
	octets = all->tximg->tx_bpp >> 3;
	index = (all->tximg->tx_ll * all->wtex.texY) + (octets * all->wtex.texX);
	while (++i < octets - 1)
		color += all->tximg[all->wtex.texNum].tx_addr[index++] << (i << 3);
	return (color);
}

int			orient_wall(t_all *all)
{
	int o;

	if (all->ray.rayDirY >= 0 && all->ray.rayDirX >= 0 && all->ray.side == 0)
		o = 0;
	else if (all->ray.rayDirY >= 0 && all->ray.rayDirX >= 0 && all->ray.side == 1)
		o = 1;
	else if (all->ray.rayDirY >= 0 && all->ray.rayDirX < 0 && all->ray.side == 0)
		o = 0;
	else if (all->ray.rayDirY >= 0 && all->ray.rayDirX < 0 && all->ray.side == 1)
		o = 3;
	else if (all->ray.rayDirY < 0 && all->ray.rayDirX > 0 && all->ray.side == 0)
		o = 2;
	else if (all->ray.rayDirY < 0 && all->ray.rayDirX >= 0 && all->ray.side == 1)
		o = 1;
	else if (all->ray.rayDirY < 0 && all->ray.rayDirX < 0 && all->ray.side == 0)
		o = 2;
	else if (all->ray.rayDirY < 0 && all->ray.rayDirX < 0 && all->ray.side == 1)
		o = 3;

	return (o);
}

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

void		calc_pos_tex_to_wall(t_all *all, int z)
{
	int y;
	int i;

	i = 0;
	y = all->game.drawSt;
	all->wtex.texPos = (all->game.drawSt - all->map.resH / 2 + all->game.lineH / 2) * all->wtex.texStep;
	all->wtex.buff = malloc(all->game.lineH * sizeof(uint32_t));
	while (y < all->game.drawEn)
	{
		all->wtex.texY = (int)all->wtex.texPos & (all->wtex.texH - 1);
		all->wtex.texPos += all->wtex.texStep;
		all->game.color = get_color_from_addr(all);
		if (all->ray.side == 1)
			all->game.color = (all->game.color >> 1) & 8355711;
		all->wtex.buff[i] = all->game.color;
		i++;
		y++;
	}
}

void		texture_line(t_all *all, int z)
{
	if (all->map.map[all->ray.mapY][all->ray.mapX] == '1')
		all->wtex.texNum = orient_wall(all);
	else
		all->wtex.texNum = all->map.map[all->ray.mapY][all->ray.mapX] - 46;
	all->wtex.texH = all->tximg[all->wtex.texNum].height;
	all->wtex.texW = all->tximg[all->wtex.texNum].width;
	calc_pos_wall_hit(all);
	all->wtex.texStep = 1.0 * ((double)all->wtex.texH / (double)all->game.lineH);
	calc_pos_tex_to_wall(all, z);
}