/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/28 20:33:17 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_vars	vars;

	int x;

	x = 0;
	fd = open("map.cub", O_RDONLY);
	if (argc == 1)
	{
		while ((nbytes = ft_get_next_line(fd, &line)) > 0)
		{
			if (x < 8)/////////////////////////////////////////////////////////////////////////
				ft_printf("DOC: >%s\n", line);/////////////////////////////////////////////////
			x++;
			vars = management_dotcub(line, vars);
		}
		close(fd);
		ft_printf("\nResolution: %dx%d\n", vars.res_width, vars.res_heigth);///////////////////
		ft_printf("PATH NO: %s\n", vars.path_N);///////////////////////////////////////////////
		ft_printf("PATH SO: %s\n", vars.path_S);///////////////////////////////////////////////
		ft_printf("PATH WE: %s\n", vars.path_W);///////////////////////////////////////////////
		ft_printf("PATH EA: %s\n", vars.path_E);///////////////////////////////////////////////
		ft_printf("PATH SPRITE: %s\n", vars.path_I);///////////////////////////////////////////
		ft_printf("COLOR FLOOR: %d\n", vars.color_floor);//////////////////////////////////////

		//<- FUNCION JUEGO
	}
	else
	{
		ft_printf("ERROR 01: MISSING MAP!");
	}
	return (0);
}
