/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:26:23 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/26 22:56:50 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		read_tex(t_vars *vars, t_tximg *tximg, char *path)
{
	
}

int		load_textures(t_all *all)
{
	if (all->map.path_N)
		if (read_tex(&all->vars, &all->tximg[0], all->map.path_N) == -1)
			return (-1);
	if (all->map.path_E)
		if (read_tex(&all->vars, &all->tximg[1], all->map.path_E) == -1)
			return (-1);
	if (all->map.path_S)
		if (read_tex(&all->vars, &all->tximg[2], all->map.path_S) == -1)
			return (-1);
	if (all->map.path_W)
		if (read_tex(&all->vars, &all->tximg[3], all->map.path_W) == -1)
			return (-1);
	if (all->map.path_I)
		if (read_tex(&all->vars, &all->tximg[4], all->map.path_I) == -1)
			return (-1);
	return (1);
}