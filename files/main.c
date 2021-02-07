/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/06 13:41:37 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_all	all;

	fd = open("map.cub", O_RDONLY);
	if (argc == 1)
	{
		all.map.map = (char **)malloc(size_width * size_height * sizeof(char *));
		while ((nbytes = ft_get_next_line(fd, &line)) >= 0)
		{
			all.map = management_dotcub(line, all.map);
			if (nbytes == 0)
				break;
		}
		close(fd);
		all.vars.mlx = mlx_init();
		if (management_dotcub_errors(&all.map, &all.vars) == -1)
			return (0);
		init_game(all);
	}
	else
		ft_printf("MISSING MAP!\n");
	return (0);
}