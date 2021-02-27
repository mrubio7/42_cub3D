/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:53:43 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:10:47 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_pj *pj, t_map *map)
{
	if (map->map[(int)(pj->posy + (pj->diry * 0.2))]\
				[(int)(pj->posx + (pj->dirx * 0.2))] != '1')
	{
		pj->posy += pj->diry * 0.1;
		pj->posx += pj->dirx * 0.1;
	}
	else if ((map->map[(int)(pj->posy)]\
			[(int)(pj->posx + (pj->dirx * 0.2))] != '1'))
		pj->posx += pj->dirx * 0.1;
	else if (map->map[(int)(pj->posy + (pj->diry * 0.2))]\
			[(int)(pj->posx)] != '1')
		pj->posy += pj->diry * 0.1;
}

void	move_s(t_pj *pj, t_map *map)
{
	if (map->map[(int)(pj->posy - (pj->diry * 0.2))]\
				[(int)(pj->posx - (pj->dirx * 0.2))] != '1')
	{
		pj->posy -= pj->diry * 0.1;
		pj->posx -= pj->dirx * 0.1;
	}
	else if ((map->map[(int)(pj->posy)]\
			[(int)(pj->posx - (pj->dirx * 0.2))] != '1'))
		pj->posx -= pj->dirx * 0.1;
	else if (map->map[(int)(pj->posy - (pj->diry * 0.2))]\
			[(int)(pj->posx)] != '1')
		pj->posy -= pj->diry * 0.1;
}

void	move_arrow_left(t_pj *pj)
{
	double olddirx;
	double oldplanex;

	olddirx = pj->dirx;
	oldplanex = pj->planex;
	pj->dirx = pj->dirx * cos(-0.05) - pj->diry * sin(-0.05);
	pj->diry = olddirx * sin(-0.05) + pj->diry * cos(-0.05);
	pj->planex = pj->planex * cos(-0.05) - pj->planey * sin(-0.05);
	pj->planey = oldplanex * sin(-0.05) + pj->planey * cos(-0.05);
}

void	move_arrow_right(t_pj *pj)
{
	double olddirx;
	double oldplanex;

	olddirx = pj->dirx;
	oldplanex = pj->planex;
	pj->dirx = pj->dirx * cos(0.05) - pj->diry * sin(0.05);
	pj->diry = olddirx * sin(0.05) + pj->diry * cos(0.05);
	pj->planex = pj->planex * cos(0.05) - pj->planey * sin(0.05);
	pj->planey = oldplanex * sin(0.05) + pj->planey * cos(0.05);
}

int		movement_pj(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		move_w(&all->pj, &all->map);
	if (keycode == KEY_S)
		move_s(&all->pj, &all->map);
	if (keycode == KEY_A)
		move_left(&all->pj, &all->map);
	if (keycode == KEY_D)
		move_right(&all->pj, &all->map);
	if (keycode == KEY_ARROW_LEFT)
		move_arrow_left(&all->pj);
	if (keycode == KEY_ARROW_RIGHT)
		move_arrow_right(&all->pj);
	return (0);
}
