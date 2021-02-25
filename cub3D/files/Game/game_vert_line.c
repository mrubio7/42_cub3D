/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_vert_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:26:44 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:10:46 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda_params(t_ray *ray, t_pj *pj)
{
	ray->hit = 0;
	ray->mapx = (int)pj->posx;
	ray->mapy = (int)pj->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (pj->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - pj->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (pj->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - pj->posy) * ray->deltadisty;
	}
}

void	ray_hit_dda(char **map, t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
	if (map[ray->mapy][ray->mapx] == '1')
		ray->hit = 1;
}

void	calc_drawline(t_game *game, t_map *map, t_ray *ray, t_pj *pj)
{
	if (ray->side == 0)
		game->perpwalldist = (ray->mapx - pj->posx +\
							(1 - ray->stepx) / 2) / ray->raydirx;
	else
		game->perpwalldist = (ray->mapy - pj->posy +\
							(1 - ray->stepy) / 2) / ray->raydiry;
	game->lineh = (int)(map->resh / game->perpwalldist);
	game->drawst = (-game->lineh / 2) + (map->resh / 2);
	if (game->drawst < 0)
		game->drawst = 0;
	game->drawen = (game->lineh / 2) + (map->resh / 2);
	if (game->drawen >= map->resh)
		game->drawen = map->resh - 1;
}

int		v_line(t_all *all, int z)
{
	all->pj.camerax = (2 * z) / (double)(all->map.resw) - 1;
	all->ray.raydirx = all->pj.dirx + all->pj.planex * all->pj.camerax;
	all->ray.raydiry = all->pj.diry + all->pj.planey * all->pj.camerax;
	init_dda_params(&all->ray, &all->pj);
	while (all->ray.hit == 0)
		ray_hit_dda(all->map.map, &all->ray);
	calc_drawline(&all->game, &all->map, &all->ray, &all->pj);
	texture_line(all, z);
	put_pixels(all, z);
	free(all->wtex.buff);
	return (0);
}
