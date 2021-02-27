/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:30:09 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:10:48 by mrubio           ###   ########.fr       */
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
	pj.dirx = 0;
	pj.diry = 0;
	pj.planex = 0;
	pj.planey = 0;
	if (pos == 'N')
	{
		pj.diry = -1;
		pj.planex = -0.90;
	}
	else if (pos == 'S')
	{
		pj.diry = 1;
		pj.planex = 0.90;
	}
	else if (pos == 'W')
	{
		pj.dirx = -1;
		pj.planey = 0.90;
	}
	else if (pos == 'E')
	{
		pj.dirx = 1;
		pj.planey = -0.90;
	}
	return (pj);
}

t_pj		detect_start_pos(char **map, t_pj pj)
{
	char	pos;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		if ((pos = ft_strchr_one("NSEW", map[y][x])) != (char)NULL)
		{
			pj = dir_pos(pos, pj);
			pj.posx = x + 0.5f;
			pj.posy = y + 0.5f;
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
