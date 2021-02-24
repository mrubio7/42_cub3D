/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:07:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 21:27:36 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			get_color_from_addr(t_all *all, int n)
{
	int				pos;
	unsigned int	color;
	int				octs;
	int				i;

	color = 0;
	i = 0;
	octs = all->tximg[n].tx_bpp / 8;
	pos = (all->tximg[n].tx_ll * all->wtex.texy) + (octs * all->wtex.texX);
	while (i < octs)
	{
		color += all->tximg[n].tx_addr[pos++] << (i * 8);
		i++;
	}
	return (color);
}

int			orient_wall(t_all *all)
{
	if (all->ray.side == 0)
	{
		if (all->ray.raydirx < 0)
			return (3);
		else
			return (1);
	}
	else
	{
		if (all->ray.raydiry < 0)
			return (0);
		else
			return (2);
	}
}

void		calc_pos_wall_hit(t_all *all)
{
	if (all->ray.side == 0)
		all->wtex.wallX = all->pj.posy + all->game.perpwalldist * \
						all->ray.raydiry;
	else
		all->wtex.wallX = all->pj.posx + all->game.perpwalldist * \
						all->ray.raydirx;
	all->wtex.wallX -= floor((all->wtex.wallX));
	all->wtex.texX = (all->wtex.wallX * (double)all->wtex.texw);
	if (all->ray.side == 0 && all->ray.raydirx > 0)
		all->wtex.texX = all->wtex.texw - all->wtex.texX - 1;
	if (all->ray.side == 1 && all->ray.raydiry < 0)
		all->wtex.texX = all->wtex.texw - all->wtex.texX - 1;
	all->wtex.texX = (double)all->wtex.texw - all->wtex.texX;
}

void		calc_pos_tex_to_wall(t_all *all, int z)
{
	int y;
	int i;

	i = 0;
	y = all->game.drawst;
	all->wtex.texpos = (all->game.drawst - all->map.resH / 2 + \
						all->game.lineh / 2) * all->wtex.texStep;
	all->wtex.buff = malloc(all->game.lineh * sizeof(unsigned int));
	while (y < all->game.drawen)
	{
		all->wtex.texy = (int)all->wtex.texpos & (all->wtex.texh - 1);
		all->wtex.texpos += all->wtex.texStep;
		all->game.color = get_color_from_addr(all, all->wtex.texNum);
		all->wtex.buff[i] = all->game.color;
		i++;
		y++;
	}
}

void		texture_line(t_all *all, int z)
{
	if (all->map.map[all->ray.mapy][all->ray.mapx] == '1')
		all->wtex.texNum = orient_wall(all);
	else
		all->wtex.texNum = all->map.map[all->ray.mapy][all->ray.mapx] - 46;
	all->wtex.texh = all->tximg[all->wtex.texNum].height;
	all->wtex.texw = all->tximg[all->wtex.texNum].width;
	calc_pos_wall_hit(all);
	all->wtex.texStep = 1.0 * ((double)all->wtex.texh / \
						(double)all->game.lineh);
	calc_pos_tex_to_wall(all, z);
}
