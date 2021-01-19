/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:53:43 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 18:10:50 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_pj *pj)
{
	printf("S");
}

int		movement_pj(int keycode, t_pj *pj)
{
	if (keycode == KEY_W)
	{
		write(1, "HOLA", 4);
		pj->posY += pj->dirY * 1;
		pj->posX += pj->dirX * 1;
	}
	return (0);
}