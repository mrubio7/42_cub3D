/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/09 00:20:51 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_map	map;
	int r;

	r = 0;

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
		if (management_dotcub_errors(&map) == -1)
		{
			ft_printf("MAP READ ERROR\n");
			return (0);
		}
		//<- FUNCION JUEGO
	}
	else
		ft_printf("MISSING MAP!\n");
	return (0);
}
