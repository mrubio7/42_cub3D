/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:53:43 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/20 16:08:56 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_pj *pj, t_map *map)
{
		pj->posY += pj->dirY * 0.1;
		pj->posX += pj->dirX * 0.1;
}

void	move_s(t_pj *pj, t_map *map)
{
		pj->posY += pj->dirY * -0.1;
		pj->posX += pj->dirX * -0.1;
}

void	move_a(t_pj *pj)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pj->dirX;
	oldPlaneX = pj->planeX;
	pj->dirX = pj->dirX * cos(-0.05) - pj->dirY * sin(-0.05);
	pj->dirY = oldDirX * sin(-0.05) + pj->dirY * cos(-0.05);
	pj->planeX = pj->planeX * cos(-0.05) - pj->planeY * sin(-0.05);
	pj->planeY = oldPlaneX * sin(-0.05) + pj->planeY * cos(-0.05);
}

void	move_d(t_pj *pj)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pj->dirX;
	oldPlaneX = pj->planeX;
	pj->dirX = pj->dirX * cos(0.05) - pj->dirY * sin(0.05);
	pj->dirY = oldDirX * sin(0.05) + pj->dirY * cos(0.05);
	pj->planeX = pj->planeX * cos(0.05) - pj->planeY * sin(0.05);
	pj->planeY = oldPlaneX * sin(0.05) + pj->planeY * cos(0.05);
}

int		movement_pj(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		move_w(&all->pj, &all->map);
	if (keycode == KEY_S)
		move_s(&all->pj, &all->map);
	if (keycode == KEY_A)
		move_a(&all->pj);
	if (keycode == KEY_D)
		move_d(&all->pj);
	return (0);
}