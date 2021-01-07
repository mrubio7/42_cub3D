/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:21:07 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/04 19:42:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map		management_dotcub_res(char *line, t_map *map)
{
	int x;

	x = 2;
	map->res_heigth = 0;
	map->res_width = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->res_width = (map->res_width * 10) + (int)line[x] - 48;
		x++;
	}
	x++;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->res_heigth = (map->res_heigth * 10) + (int)line[x] - 48;
		x++;
	}
	return (*map);
}