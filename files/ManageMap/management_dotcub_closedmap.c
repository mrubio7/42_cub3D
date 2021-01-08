/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_closedmap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:29:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/08 21:14:38 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			readmap_zero4dir(char **map, int row, int x)
{
	if (ft_strchr("210NSEW", map[row][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row + 1][x]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row - 1][x]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row - 1][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row + 1][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row + 1][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("210NSEW", map[row - 1][x + 1]) == NULL)
		return (-1);
	return (1);
}

int			management_dotcub_closedmap(char **map)
{
	int row;
	int x;

	row = 1;
	x = 0;
	while (map[row][x] == '1')
	{
		if (readmap_zero4dir(map, row, x) == -1)
			return (-1);
		if (map[row][x] == '\0')
		{
			row++;
			x = 0;
		}
		else
			x++;
	}
	return (0);
}
