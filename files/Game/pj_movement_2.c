/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_movement_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:32:31 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 10:44:44 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_left(t_pj *pj, t_map *map)
{
	if (map->map[(int)(pj->posY + (pj->dirY * 0.2))][(int)(pj->posX + (pj->dirX * 0.2))] != '1')
	{
		pj->posX -= 0.1;
	}
	else if ((map->map[(int)(pj->posY)][(int)(pj->posX + (pj->dirX * 0.2))] != '1'))
		pj->posX += pj->dirX * 0.1;
	else if (map->map[(int)(pj->posY + (pj->dirY * 0.2))][(int)(pj->posX)] != '1')
		pj->posY += pj->dirY * 0.1;
}