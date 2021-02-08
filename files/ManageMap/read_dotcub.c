/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dotcub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:12:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/08 09:28:05 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			read_dotcub(t_all *all, char *argv)
{
	int		fd;
	int		nbytes;
	char	*line;

	fd = open("map.cub", O_RDONLY);
	all->map.map = (char **)malloc(size_width * size_height * sizeof(char **));
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