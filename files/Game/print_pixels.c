/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:37:16 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/25 20:19:07 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		put_pixels(t_all *all, int z)
{
	int x;

	x = 0;
	if (all->game.lineH > all->map.resH)
		all->game.lineH = all->map.resH;
	while (x < all->game.drawEn && all->game.lineH < all->map.resH)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x, all->map.color_c);
		x++;
	}
	x = 0;
	while (x < all->game.lineH)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x + all->game.drawSt,\
						 all->wtex.buff[x]);
		x++;
	}
	free(all->wtex.buff);
	while ((x + all->game.drawSt) < all->map.resH \
			&& all->game.lineH < all->map.resH)
	{
		my_mlx_pixel_put(&all->img, all->map.resW - z, x + all->game.drawSt,\
						 all->map.color_f);
		x++;
	}
}
