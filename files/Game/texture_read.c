/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:26:23 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/27 23:30:35 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		read_tex(t_vars *vars, t_tximg *tximg, char *path)
{
	tximg->tx_addr = malloc(128 * 128 * sizeof(int *));
	if ((tximg->tx = mlx_xpm_file_to_image(vars->mlx, path, &tximg->width, &tximg->height))) // No entra CHECK
	{
		tximg->tx_addr = (int *)mlx_get_data_addr(tximg->tx, &tximg->tx_bpp, &tximg->tx_ll, &tximg->tx_endian);
		return (0);
	}
	return (-1);
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