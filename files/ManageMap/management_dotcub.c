/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:17:48 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/20 16:09:34 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		management_dotcub(char *line, t_map *map)
{
	static int row;

	if (line[0] == 'R')
		management_dotcub_res(line, map);
	else if (line[0] == 'N' && line[1] == 'O')
		map->path_N = management_dotcub_path(line);
	else if (line[0] == 'S' && line[1] == 'O')
		map->path_S = management_dotcub_path(line);
	else if (line[0] == 'W' && line[1] == 'E')
		map->path_W = management_dotcub_path(line);
	else if (line[0] == 'E' && line[1] == 'A')
		map->path_E = management_dotcub_path(line);
	else if (line[0] == 'S' && line[1] == ' ')
		map->path_I = management_dotcub_path_sprite(line);
	else if (line[0] == 'F' && line[1] == ' ')
		map->color_f = management_dotcub_color(line);
	else if (line[0] == 'C' && line[1] == ' ')
		map->color_c = management_dotcub_color(line);
	else if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
	{
		map->map[row] = ft_strdup(line);
		map->map[row + 1] = NULL;
		row++;
	}
	return (row);
}
