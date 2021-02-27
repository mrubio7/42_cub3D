/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/27 10:50:35 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	t_all	all;
	int		check;

	ft_bzero(&all, sizeof(t_all));
	if (argc == 3)
	{
		if ((check = ft_strncmp("--save", argv[2], 7)) == 0)
			all.vars.bmp = 1;
	}
	if (argc > 1 && argc < 4)
	{
		all.vars.mlx = mlx_init();
		if (read_dotcub(&all, argv[1]) == -1)
			return (0);
		if (argc == 2 || (check == 0 && argc == 3))
			init_game(&all);
	}
	if ((check > 0 && argc > 2) || argc > 2)
		perror("ERROR\nUnrecognized argument");
	else if (argc == 1)
		perror("ERROR\nMissing map");
	return (0);
}
