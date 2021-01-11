/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/11 23:46:44 by mrubio           ###   ########.fr       */
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

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
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