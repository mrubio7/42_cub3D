/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:21:07 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:06:40 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		management_dotcub_res(char *line, t_map *map)
{
	int x;

	x = 2;
	map->resh = 0;
	map->resw = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resw = (map->resw * 10) + (int)line[x] - 48;
		x++;
	}
	x++;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resh = (map->resh * 10) + (int)line[x] - 48;
		x++;
	}
	while ((map->resw % 4) != 0)
		map->resw--;
}
