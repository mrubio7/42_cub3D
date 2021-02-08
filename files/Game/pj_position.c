/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:30:09 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/05 17:38:09 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		ft_strchr_one(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char)c);
		i++;
	}
	if (s[i] == c)
		return ((char)c);
	return ((char)NULL);
}

t_pj		dir_pos(char pos, t_pj pj)
{
	pj.dirX = 0;
	pj.dirY = 0;
	pj.planeX = 0;
	pj.planeY = 0;
	if (pos == 'N')
	{
		pj.dirY = -1;
		pj.planeX = -0.90;
	}
	else if (pos == 'S')
	{
		pj.dirY = 1;
		pj.planeX = 0.90;
	}
	else if (pos == 'W')
	{
		pj.dirX = -1;
		pj.planeY = 0.90;
	}
	else if (pos == 'E')
	{
		pj.dirX = 1;
		pj.planeY = -0.90;
	}
	return (pj);
}

t_pj		detect_start_pos(char **map, t_pj pj)
{
	char pos;
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		if ((pos = ft_strchr_one("NSEW", map[y][x])) != (char)NULL)
		{
			pj = dir_pos(pos, pj);
			pj.posX = x + 0.2;
			pj.posY = y;
			return (pj);
		}
		else
			x += 1;
		if (map[y][x] == '\0')
		{
			y += 1;
			x = 0;
		}
	}
	return (pj);
}