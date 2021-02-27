/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:26:23 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 16:56:11 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		read_tex(t_vars *vars, t_tximg *tximg, char *path)
{
	if (!(tximg->tx = mlx_xpm_file_to_image(vars->mlx, path,
											&(tximg->width), &(tximg->height))))
		return (-1);
	tximg->tx_addr = mlx_get_data_addr(tximg->tx, &(tximg->tx_bpp),
									&(tximg->tx_ll), &(tximg->tx_endian));
	return (0);
}

int		load_textures(t_all *all)
{
	all->tximg = malloc(sizeof(t_tximg) * 7);
	if (read_tex(&(all->vars), &(all->tximg[0]), all->map.path_n) == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[1]), all->map.path_e) == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[2]), all->map.path_s) == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[3]), all->map.path_w) == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[4]), all->map.path_i) == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[5]), "./textures/Jail.xpm") == -1)
		return (-1);
	if (read_tex(&(all->vars), &(all->tximg[6]), "./textures/Hands.xpm") == -1)
		return (-1);
	return (1);
}
