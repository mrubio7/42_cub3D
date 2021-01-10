/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:30:09 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/10 19:53:25 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vars			detect_start_pos(char **map, t_vars vars)
{
	vars.posX = 0;
	vars.posY = 0;
	while (map[vars.posY][vars.posX])
	{
		if (ft_strchr("NSEW", map[vars.posY][vars.posX]) != NULL)
			return (vars);
		else
			vars.posX++;
		if (map[vars.posY][vars.posX] == '\0')
		{
			vars.posY++;
			vars.posX = 0;
		}
	}
	return (vars);
}