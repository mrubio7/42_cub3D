/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_movement_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:32:31 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 21:27:34 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_left(t_pj *pj, t_map *map)
{
	if (map->map[(int)(pj->posy - (pj->dirx * 0.1))]\
				[(int)(pj->posx + (pj->dirY * 0.1))] != '1')
	{
		pj->posy -= pj->dirx * 0.1;
		pj->posx += pj->dirY * 0.1;
	}
	else if ((map->map[(int)(pj->posy)]\
			[(int)(pj->posx + (pj->dirY * 0.1))] != '1'))
		pj->posx += pj->dirY * 0.1;
	else if (map->map[(int)(pj->posy - (pj->dirx * 0.1))]\
			[(int)(pj->posx)] != '1')
		pj->posy -= pj->dirx * 0.1;
}

void	move_right(t_pj *pj, t_map *map)
{
	if (map->map[(int)(pj->posy + (pj->dirx * 0.1))]\
				[(int)(pj->posx - (pj->dirY * 0.1))] != '1')
	{
		pj->posy += pj->dirx * 0.1;
		pj->posx -= pj->dirY * 0.1;
	}
	else if ((map->map[(int)(pj->posy)]\
			[(int)(pj->posx - (pj->dirY * 0.1))] != '1'))
		pj->posx -= pj->dirY * 0.1;
	else if (map->map[(int)(pj->posy + (pj->dirx * 0.1))]\
			[(int)(pj->posx)] != '1')
		pj->posy += pj->dirx * 0.1;
}
