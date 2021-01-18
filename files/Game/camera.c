/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:10:00 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/17 13:20:59 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		init_camera_pos(t_pj *pj, double dirX, double dirY, double planeX, double planeY)
{
	pj->dirX = dirX;
	pj->dirY = dirY;
	pj->planeX = planeX;
	pj->planeY = planeY;
}