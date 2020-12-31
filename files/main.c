/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/31 15:36:14 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_map	map;
	t_vars	vars;
	
	int x;
	
	x = 0;
	fd = open("map.cub", O_RDONLY);
	if (argc == 1)
	{
		while ((nbytes = ft_get_next_line(fd, &line)) > 0)
		{
			ft_printf("DOC: >%s\n", line);////////////////////////////////////////////////////
			map = management_dotcub(line, map);
		}
		close(fd);
		ft_printf("\nResolution: %dx%d\n", map.res_width, map.res_heigth);////////////////////
		ft_printf("PATH NO: %s\n", map.path_N);///////////////////////////////////////////////
		ft_printf("PATH SO: %s\n", map.path_S);///////////////////////////////////////////////
		ft_printf("PATH WE: %s\n", map.path_W);///////////////////////////////////////////////
		ft_printf("PATH EA: %s\n", map.path_E);///////////////////////////////////////////////
		ft_printf("PATH SPRITE: %s\n", map.path_I);///////////////////////////////////////////
		ft_printf("COLOR FLOOR: %x\n", map.color_floor);//////////////////////////////////////
		ft_printf("COLOR CEILING: %x\n", map.color_ceiling);//////////////////////////////////
		while (x <= 15)
		{
			ft_printf("MAP: %s\n", map.map[x]);///////////////////////////////////////////////
			x++;
		}
		//<- FUNCION JUEGO
	}
	else
	{
		ft_printf("ERROR 01: MISSING MAP!");
	}
	return (0);
}
