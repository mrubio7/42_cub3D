/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:30:14 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/31 15:52:23 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		*management_dotcub_map(char *line)
{
	int		x;
	char	*map_row;

	x = 0;
	while (line[x])
		x++;
	map_row = (char *)malloc(x + 2);
	x = 0;
	while (line[x] != '\0')
	{
		map_row[x] = line[x];
		x++;
	}
	map_row[x] = '\0';
	return (map_row);
}