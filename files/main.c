/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:57:35 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:08:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		nbytes;
	char	*line;
	t_vars	vars;

	fd = open("map.cub", O_RDONLY);
	if (argc == 1)
	{
		while ((nbytes = ft_get_next_line(fd, &line)) > 0)
		{
			line[nbytes] = '\0';
			vars = management_dotcub(line, vars);
		}
		//<- FUNCION JUEGO
	}
	else
	{
		printf("ERROR 01: MISSING MAP!");
	}
	return (0);
}
