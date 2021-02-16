/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dotcub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:12:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/16 19:09:06 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			read_dotcub(t_all *all, char *mapname)
{
	int		fd;
	int		nbytes;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd > 1)
	{
		while ((nbytes = ft_get_next_line(fd, &line)) >= 0)
		{
			all->map = management_dotcub(line, all->map);
			if (nbytes == 0)
				break;
		}
			close(fd);
		if (management_dotcub_errors(&all->map, &all->vars) == -1)
				return (-1);
		return (1);
	}
	perror("Map error");
	return (-1);
}