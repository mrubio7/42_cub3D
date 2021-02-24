/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:37:16 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 21:27:33 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color, t_all *all)
{
	char	*dst;

	if (x <= all->map.resW && y <= all->map.resH)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void		put_f_and_c(t_all *all, int z, int x)
{
	while ((x + all->game.drawst) < all->map.resH \
			&& all->game.lineh < all->map.resH)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x + all->game.drawst,\
						all->map.color_f, all);
		x++;
	}
	x = 0;
	if (all->game.lineh > all->map.resH)
		all->game.lineh = all->map.resH - 1;
	while (x < all->game.drawen && all->game.lineh < all->map.resH)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x, all->map.color_c, all);
		x++;
	}
}

void		put_walls(t_all *all, int z)
{
	int x;

	x = 0;
	while (x < all->game.lineh && (all->map.resW - z) > 0)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x + all->game.drawst,\
						all->wtex.buff[x], all);
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
