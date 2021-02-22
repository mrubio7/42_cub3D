/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_closedmap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:29:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/20 16:08:12 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			readmap_zero8dir(char **map, int y, int x)
{
	if (ft_strchr("210NEWS", map[y][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y + 1][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y + 1][x]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y + 1][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y - 1][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y - 1][x]) == NULL)
		return (-1);
	if (ft_strchr("210NEWS", map[y - 1][x + 1]) == NULL)
		return (-1);
	return (1);
}

int			management_dotcub_closedmap(char **map)
{
	int row;
	int x;

	row = 0;
	x = 0;
	while ((map[row][x]))
	{
		if (map[row][x] == '0' && (!(map[row - 1]) || !(map[row + 1])))
			return (-1);
		if (map[row][x] == '0')
		{
			if (readmap_zero8dir(map, row, x) == -1)
				return (-1);
		}
		x++;
		if (map[row][x] == '\0')
		{
			if (!(map[row + 1]))
				return (1);
			row++;
			x = 0;
		}
	}
	return (-1);
}
