/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:21:07 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/27 11:28:52 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		check_res(t_map *map)
{
	if (map->resw < 400)
		map->resw = 400;
	if (map->resh < 400)
		map->resh = 400;
	while ((map->resw % 4) != 0)
		map->resw--;
}

void		management_dotcub_res(char *line, t_map *map)
{
	int x;
	int c;

	x = 2;
	c = 0;
	map->resh = 0;
	map->resw = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resw = (map->resw * 10) + (int)line[x++] - 48;
		c++;
		if (c == 6)
			break ;
	}
	x++;
	c = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		map->resh = (map->resh * 10) + (int)line[x++] - 48;
		c++;
		if (c == 6)
			break ;
	}
	check_res(map);
}
