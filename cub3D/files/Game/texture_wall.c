/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:07:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:12:35 by mrubio           ###   ########.fr       */
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
	pos = (all->tximg[n].tx_ll * all->wtex.texy) + (octs * all->wtex.texx);
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
		all->wtex.wallx = all->pj.posy + all->game.perpwalldist * \
						all->ray.raydiry;
	else
		all->wtex.wallx = all->pj.posx + all->game.perpwalldist * \
						all->ray.raydirx;
	all->wtex.wallx -= floor((all->wtex.wallx));
	all->wtex.texx = (all->wtex.wallx * (double)all->wtex.texw);
	if (all->ray.side == 0 && all->ray.raydirx > 0)
		all->wtex.texx = all->wtex.texw - all->wtex.texx - 1;
	if (all->ray.side == 1 && all->ray.raydiry < 0)
		all->wtex.texx = all->wtex.texw - all->wtex.texx - 1;
	all->wtex.texx = (double)all->wtex.texw - all->wtex.texx;
}

void		calc_pos_tex_to_wall(t_all *all, int z)
{
	int y;
	int i;

	i = 0;
	y = all->game.drawst;
	all->wtex.texpos = (all->game.drawst - all->map.resh / 2 + \
						all->game.lineh / 2) * all->wtex.texstep;
	all->wtex.buff = malloc(all->game.lineh * sizeof(unsigned int));
	while (y < all->game.drawen)
	{
		all->wtex.texy = (int)all->wtex.texpos & (all->wtex.texh - 1);
		all->wtex.texpos += all->wtex.texstep;
		all->game.color = get_color_from_addr(all, all->wtex.texnum);
		all->wtex.buff[i] = all->game.color;
		i++;
		y++;
	}
}

void		texture_line(t_all *all, int z)
{
	if (all->map.map[all->ray.mapy][all->ray.mapx] == '1')
		all->wtex.texnum = orient_wall(all);
	else
		all->wtex.texnum = all->map.map[all->ray.mapy][all->ray.mapx] - 46;
	all->wtex.texh = all->tximg[all->wtex.texnum].height;
	all->wtex.texw = all->tximg[all->wtex.texnum].width;
	calc_pos_wall_hit(all);
	all->wtex.texstep = 1.0 * ((double)all->wtex.texh / \
						(double)all->game.lineh);
	calc_pos_tex_to_wall(all, z);
}
