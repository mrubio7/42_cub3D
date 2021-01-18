/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/17 22:08:57 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_vars *vars, t_map *map, t_pj pj, t_ray ray, t_game game, t_img *img)
{
	int z;

	z = 0;
	img->img = mlx_new_image(vars->mlx, map->res_width, map->res_heigth);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, 
								&img->line_length, &img->endian);
	while (z < map->res_width)
	{
		v_line(vars, &ray, &pj, &game, map, img, z);
		z++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
	return (0);
}