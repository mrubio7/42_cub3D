/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dotcub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:12:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 18:43:14 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			read_dotcub(t_all *all, char *mapname)
{
	int		fd;
	int		nbytes;
	char	*line;
	int		rows;

	fd = open(mapname, O_RDONLY);
	if (fd > 1)
	{
		all->map.map = malloc(SIZE_WIDTH * SIZE_HEIGHT * sizeof(char **));
		while ((nbytes = ft_get_next_line(fd, &line)) >= 0)
		{
			management_dotcub(line, &all->map);
			if (nbytes == 0)
				break ;
		}
		close(fd);
		//free(line);
		if (management_dotcub_errors(&all->map, &all->vars) == -1)
			return (-1);
		return (1);
	}
	perror("Map error");
	return (-1);
}
