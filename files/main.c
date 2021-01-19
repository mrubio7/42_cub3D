/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 17:57:46 by mrubio           ###   ########.fr       */
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
		vars.mlx = mlx_init();
		if (management_dotcub_errors(&map, &vars) == -1)
			return (0);
		init_game(map, vars);
	}
	else
		ft_printf("MISSING MAP!\n");
	return (0);
}