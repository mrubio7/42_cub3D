/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:50:53 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 22:58:23 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		init_sprites(t_all *all)
{
	int x;
	int y;
	int sp;

	sp = 0;
	x = 0;
	y = 0;
	all->spos = malloc(sizeof(t_spos) * 100);
	while (all->map.map[y] != '\0')
	{
		if (all->map.map[y][x] == '2')
		{
			all->spos[sp].x = x + 0.5f;
			all->spos[sp].y = y + 0.5f;
			all->spos[sp].tex = 4;
			sp++;
		}
		x++;
		if (all->map.map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
}
