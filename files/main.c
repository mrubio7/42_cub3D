/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 12:21:40 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	t_all	all;

	if (argc > 0)
	{
		if (read_dotcub(&all, argv[1]) == -1)
			return (0);
		all.vars.mlx = mlx_init();
		init_game(all);
	}
	else
		ft_printf("MISSING MAP!\n");
	return (0);
}