/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:37:16 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:09:53 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *\
		(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		put_f_and_c(t_all *all, int z, int x)
{
	while ((x + all->game.drawst) < all->map.resh \
			&& all->game.lineh < all->map.resh)
	{
		my_mlx_pixel_put(&all->img, all->map.resw - z, x + all->game.drawst,\
						all->map.color_f);
		x++;
	}
	x = 0;
	if (all->game.lineh > all->map.resh)
		all->game.lineh = all->map.resh - 1;
	while (x < all->game.drawen && all->game.lineh < all->map.resh)
	{
		my_mlx_pixel_put(&all->img, all->map.resw - z, x, all->map.color_c);
		x++;
	}
}

void		put_walls(t_all *all, int z)
{
	int x;

	x = 0;
	while (x < all->game.lineh && (all->map.resw - z) > 0)
	{
		my_mlx_pixel_put(&all->img, all->map.resw - z, x + all->game.drawst,\
						all->wtex.buff[x]);
		all->wtex.buff[x] = 0;
		x++;
	}
}

void		put_pixels(t_all *all, int z)
{
	int x;

	x = 0;
	put_f_and_c(all, z, x);
	put_walls(all, z);
}
