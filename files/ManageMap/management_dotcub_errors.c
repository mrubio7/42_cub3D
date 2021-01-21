/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_errors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:37:52 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/21 16:25:06 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		management_dotcub_res_error(int width, int heigth, t_vars *vars)
{
	int sizX;
	int sizY;
	
	mlx_get_screen_size(vars->mlx, &sizX, &sizY);
	if (width > sizX || heigth > sizY)
	{
		ft_printf("MAP.CUB RESOLUTION: %d x %d\n", width, heigth);
		ft_printf("YOU ARE USING: %d x %d\n", sizX, sizY);
		return (-1);
	}
	return (1);
}

int		management_dotcub_color_error(int r, int g, int b)
{
	int x;

	x = 0;
	if (r > 255 || r < 0)
	{
		ft_printf(" - COLOR RED: OUT OF RANGE: %d/255\n", r);
		x++;
	}
	if (g > 255 || g < 0)
	{
		ft_printf(" - COLOR GREEN: OUT OF RANGE: %d/255\n", g);
		x++;
	}
	if (b > 255 || b < 0)
	{
		ft_printf(" - COLOR BLUE: OUT OF RANGE: %d/255\n", b);
		x++;
	}
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
		if (ft_strchr("NEWS", map[row][x]) != NULL)
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
	int r;

	r = 0;
	if (management_dotcub_res_error(map->resW, map->resH, vars) == -1)
	{
		ft_printf("RESOLUTION ERROR\n");
		return (-1);
	}
	else if (management_dotcub_closedmap(map->map) == -1)
	{
		ft_printf("MAP READ ERROR\n");
		return (-1);
	}
	else if (management_dotcub_mapstart(map->map) == -1)
	{
		ft_printf("ERROR: NO START POSITION IN MAP\n");
		return (-1);
	}
	else
		ft_printf("map.cub OK! :)\n");
	return (1);
}
