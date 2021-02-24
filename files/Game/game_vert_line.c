/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_vert_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:26:44 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/23 18:38:45 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda_params(t_ray *ray, t_pj *pj)
{
	ray->hit = 0;
	ray->mapX = (int)pj->posX;
	ray->mapY = (int)pj->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
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

void	ray_hit_dda(char **map, t_ray *ray)
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
	if (map[ray->mapY][ray->mapX] == '1')
		ray->hit = 1;
}

void	calc_drawline(t_game *game, t_map *map, t_ray *ray, t_pj *pj)
{
	if (ray->side == 0)
		game->perpWallDist = (ray->mapX - pj->posX +\
							(1 - ray->stepX) / 2) / ray->rayDirX;
	else
		game->perpWallDist = (ray->mapY - pj->posY +\
							(1 - ray->stepY) / 2) / ray->rayDirY;
	game->lineH = (int)(map->resH / game->perpWallDist);
	game->drawSt = (-game->lineH / 2) + (map->resH / 2);
	if (game->drawSt < 0)
		game->drawSt = 0;
	game->drawEn = (game->lineH / 2) + (map->resH / 2);
	if (game->drawEn >= map->resH)
		game->drawEn = map->resH - 1;
}

int		v_line(t_all *all, int z)
{
	all->pj.cameraX = (2 * z) / (double)(all->map.resW) - 1;
	all->ray.rayDirX = all->pj.dirX + all->pj.planeX * all->pj.cameraX;
	all->ray.rayDirY = all->pj.dirY + all->pj.planeY * all->pj.cameraX;
	init_dda_params(&all->ray, &all->pj);
	while (all->ray.hit == 0)
		ray_hit_dda(all->map.map, &all->ray);
	calc_drawline(&all->game, &all->map, &all->ray, &all->pj);
	texture_line(all, z);
	put_pixels(all, z);
	free(all->wtex.buff);
	return (0);
}
