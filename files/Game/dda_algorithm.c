/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:26:44 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/13 21:27:02 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*init_dda_params(t_ray *ray, t_pj *pj)
{
	ray->mapX = (int)pj->posX;
	ray->mapY = (int)pj->posY;
	ray->deltaDistX = abs(1 / ray->rayDirX);
	ray->deltaDistY = abs(1 / ray->rayDirY);
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (pj->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - pj->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (pj->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - pj->posY) * ray->deltaDistY;
	}
}

int		dda_algorithm(t_ray *ray, t_pj *pj, char **map)
{
	init_dda_params(&ray, &pj);
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map[ray->mapX][ray->mapY] > 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - pj->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - pj->posY + (1 - ray->stepY) / 2) / ray->rayDirY;

}