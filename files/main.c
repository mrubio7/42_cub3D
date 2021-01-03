/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/03 17:20:47 by mrubio           ###   ########.fr       */
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

	fd = open("map.cub", O_RDONLY);
	if (argc == 1)
	{
		map.map = (char **)malloc(100 * 100 * sizeof(char *));
		while ((nbytes = ft_get_next_line(fd, &line)) >= 0)
		{
			map = management_dotcub(line, map);
			if (nbytes == 0)
				break;
		}
		close(fd);
		//<- FUNCION JUEGO
	}
	else
		ft_printf("ERROR 01: MISSING MAP!");
	return (0);
}
