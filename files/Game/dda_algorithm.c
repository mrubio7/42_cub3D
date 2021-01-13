/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:26:44 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/13 20:42:47 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		preparing_dda(t_ray *ray, t_pj *pj)
{
	ray->mapX = (int)pj->posX;
	ray->mapY = (int)pj->posY;
	while (ray->hit < 0)
	{
		ray->deltaDistX = abs(1 / ray->rayDirX);
		ray->deltaDistY = abs(1 / ray->rayDirY);
		
		
	}
}