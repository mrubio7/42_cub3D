/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_closedmap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:29:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/06 23:50:11 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_rdmap		read_map_left(char **map, t_rdmap rdmap)
{
	
}

t_rdmap		read_map_down(char **map, t_rdmap rdmap)
{
	rdmap.svd_row = rdmap.row;
	rdmap.svd_col = rdmap.col;
	while (map[rdmap.row++][rdmap.col] == '1')
	{
		if (map[rdmap.row][rdmap.col + 1] == '1')
			rdmap = read_map_right(&map, rdmap);
		if (map[rdmap.row + 1][rdmap.col] == '\0')
			rdmap = read_map_left(&map, rdmap);
	}
}

t_rdmap		read_map_right(char **map, t_rdmap rdmap)
{
	rdmap.svd_row = rdmap.row;
	rdmap.svd_col = rdmap.col;
	while (map[rdmap.row][rdmap.col++] == '1')
	{
		if (map[rdmap.row][rdmap.col + 1] == '\0')
		{
			rdmap.svd_col = 0;
			rdmap.svd_row = 0;
		}
		else if (map[rdmap.row][rdmap.col + 1] != '1')
		{
			rdmap.row = rdmap.svd_row;
			rdmap.col = rdmap.svd_col;
		}
		else
			rdmap.error = 1;
	}
	return (rdmap);
}

int			management_dotcub_closedmap(char **map)
{
	t_rdmap	rdmap;

	rdmap.row = 0;
	rdmap.col = 0;
	while (map[rdmap.row][rdmap.col] != '1')
		rdmap.col++;
	rdmap.og_col = rdmap.col;
	if (map[rdmap.row][rdmap.col + 1] == '1')
		rdmap = read_map_right(&map, rdmap);
	if (map[rdmap.row + 1][rdmap.col] == '1')
		rdmap = read_map_down(&map, rdmap);


	if (rdmap.error == 1)
	{
		ft_printf("MAP ERROR\n");
		return (0);
	}
}