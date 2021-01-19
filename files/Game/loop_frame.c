/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:02:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 21:34:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		loop_frame(t_vars *vars, t_map *map, t_pj *pj, t_img *img)
{
	int z;

	z = 0;
	while (z < map->res_width)
	{
		v_line(vars, pj, map, img, z);
		z++;
		if (z == map->res_width)
		{
			mlx_clear_window(vars->mlx, vars->win);
		}
	}
	return (0);
}