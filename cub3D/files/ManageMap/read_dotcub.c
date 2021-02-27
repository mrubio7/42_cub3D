/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dotcub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:12:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/27 11:24:11 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		read_dotcub_error(t_all *all)
{
	perror("ERROR\nCould not read the map.cub");
	exit(0);
}

int			read_dotcub(t_all *all, char *mapname)
{
	int		fd;
	int		nbytes;
	char	*line;
	int		rows;

	fd = open(mapname, O_RDONLY);
	if (fd > 1)
	{
		all->map.map = malloc(50 * 50 * sizeof(char **));
		while ((nbytes = ft_get_next_line(fd, &line)) >= 0)
		{
			if (!(line[2]) && line[0] != '\0')
				read_dotcub_error(all);
			management_dotcub(line, &all->map);
			free(line);
			if (nbytes == 0)
				break ;
		}
		close(fd);
		if (management_dotcub_errors(&all->map, &all->vars) == -1)
			return (-1);
		return (1);
	}
	perror("ERROR\nMap not found");
	return (-1);
}
