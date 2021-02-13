/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dotcub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:12:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/13 17:24:50 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			read_dotcub(t_all *all, char *argv)
{
	int		fd;
	int		nbytes;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd > 0)
	{
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
	perror("Error");
	return (-1);
}