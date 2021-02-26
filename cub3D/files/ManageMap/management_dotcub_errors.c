/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_errors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:37:52 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/26 21:16:01 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		management_dotcub_res_error(t_map *map, t_vars *vars)
{
	int sizx;
	int sizy;

	mlx_get_screen_size(vars->mlx, &sizx, &sizy);
	if (map->resw > sizx)
		map->resw = sizx;
	if (map->resh > sizy)
		map->resh = sizy;
	return (1);
}

int		management_dotcub_color_error(int r, int g, int b)
{
	int x;

	x = 0;
	if (r > 255 || r < 0)
		x++;
	if (g > 255 || g < 0)
		x++;
	if (b > 255 || b < 0)
		x++;
	if (x > 0)
		return (0);
	return (1);
}

int		management_dotcub_mapstart(char **map)
{
	int row;
	int x;

	row = 0;
	x = 0;
	while (map[row][x])
	{
		if ((ft_strchr("NEWS", map[row][x])))
			return (1);
		x++;
		if (map[row][x] == '\0')
		{
			if (!(map[row + 1]))
				break ;
			row++;
			x = 0;
		}
	}
	return (-1);
}

int		management_dotcub_errors(t_map *map, t_vars *vars)
{
	management_dotcub_res_error(map, vars);
	if (management_dotcub_closedmap(map->map) == -1)
	{
		perror("ERROR\nMap is not closed");
		return (-1);
	}
	else if (management_dotcub_mapstart(map->map) == -1)
	{
		perror("ERROR\nMap haven't initial position ('N' 'S' 'W' 'E')");
		return (-1);
	}
	return (1);
}
