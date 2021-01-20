/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:26:44 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/20 16:16:35 by mrubio           ###   ########.fr       */
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

void	ray_hit_dda(t_map *map, t_ray *ray)
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
	if (map->map[ray->mapY][ray->mapX] > '0' \
		&& map->map[ray->mapY][ray->mapX] < '3')
		ray->hit = 1;
}

void	calc_drawline(t_game *game, t_map *map, t_ray *ray, t_pj *pj)
{
	if (ray->side == 0)
		game->perpWallDist = (ray->mapX - pj->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		game->perpWallDist = (ray->mapY - pj->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
	game->lineHeight = (int)(map->res_heigth / game->perpWallDist);
	game->drawStart = (-game->lineHeight / 2) + (map->res_heigth / 2);
	if (game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = (game->lineHeight / 2) + (map->res_heigth / 2);
	if (game->drawEnd >= map->res_heigth)
		game->drawEnd = map->res_heigth - 1;
}

int		v_line(t_all *all, int z)
{
	all->pj.cameraX = (2 * z) / (double)(all->map.res_width) - 1;
	all->ray.rayDirX = all->pj.dirX + all->pj.planeX * all->pj.cameraX;
	all->ray.rayDirY = all->pj.dirY + all->pj.planeY * all->pj.cameraX;
	init_dda_params(&all->ray, &all->pj);
	while (all->ray.hit == 0)
		ray_hit_dda(&all->map, &all->ray);
	calc_drawline(&all->game, &all->map, &all->ray, &all->pj);
	all->game.color = get_color_wall(&all->ray, all->map.map);
	put_pixels(&all->vars, &all->game, &all->img, z, all->map.res_width);
	return (0);
}
