/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/13 17:15:29 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	t_all	all;

	if (argc > 1)
	{
		if (argc == 3 && ft_strncmp("--save", argv[2], 7) > 0)
			all.vars.bmp = 1;
		if (read_dotcub(&all, argv[1]) == -1)
			return (0);
		all.vars.mlx = mlx_init();
		init_game(all);
	}
	else
		perror("MISSING MAP");
	return (0);
}