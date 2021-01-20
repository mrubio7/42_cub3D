/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:37:16 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/20 16:38:04 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		put_pixels(t_vars *vars, t_game *game, t_img *img, int z, int res)
{
	int x;
	
	x = 0;
	while (x < game->drawStart)
	{
		my_mlx_pixel_put(img, res-z, x, 0xBBBBBB);
		x++;
	}
	x = 0;
	while (x < game->lineHeight)
	{
		my_mlx_pixel_put(img, res-z, x + game->drawStart, game->color);
		x++;
	}
	while ((x + game->drawStart) < 600)
	{
		my_mlx_pixel_put(img, res-z, x+game->drawStart, 0x454545);
		x++;
	}
}