/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:51:42 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_vars	vars;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		while ((nbytes = ft_get_next_line(fd, &line)) > 0)
		{
			vars = management_dotcub(line, vars);
		}
		ft_printf("Resolution: %dx%d\n", vars.res_width, vars.res_heigth);
		ft_printf("Path NO: %s\n", vars.path_N);
		
		//<- FUNCION JUEGO
	}
	else
	{
		ft_printf("ERROR 01: MISSING MAP!");
	}
	return (0);
}
