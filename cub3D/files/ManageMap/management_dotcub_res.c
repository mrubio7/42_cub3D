/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:21:07 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/22 20:08:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		management_dotcub_res(char *line, t_map *map)
{
	int x;

	x = 2;
	map->resH = 0;
	map->resW = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resW = (map->resW * 10) + (int)line[x] - 48;
		x++;
	}
	x++;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resH = (map->resH * 10) + (int)line[x] - 48;
		x++;
	}
	while ((map->resW % 4) != 0)
		map->resW--;
}
