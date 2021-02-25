/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 16:50:39 by mrubio           ###   ########.fr       */
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
		if ((check = ft_strncmp("--save", argv[2], 6)) == 0)
			all.vars.bmp = 1;
	}
	if (argc > 1 && argc < 4)
	{
		if (read_dotcub(&all, argv[1]) == -1)
			return (0);
		all.vars.mlx = mlx_init();
		init_game(&all);
	}
	if (check > 0)
		perror("ERROR\nSecond arg is not '--save'");
	else
		perror("ERROR\nMissing map");
	return (0);
}
