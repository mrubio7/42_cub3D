/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:21:55 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/18 19:57:02 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_color_wall(t_ray *ray, char **map)
{
	int color;

	color = 0xFFFFFF;
	if (map[ray->mapY][ray->mapX] == '1')
		color = 0x0000FF;
	else if (map[ray->mapY][ray->mapX] == '2')
		color = 0x00FF00;
	else if (map[ray->mapY][ray->mapX] == '3')
		color = 0xFFFF00;
	else if (map[ray->mapY][ray->mapX] == '4')
		color = 0xFF0000;
	if (ray->side == 1)
		color /= 1.5;
	return (color);
}