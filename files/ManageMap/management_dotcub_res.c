/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:21:07 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 12:25:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vars		management_dotcub_res(char *line, t_vars *vars)
{
	int x;

	x = 2;
	vars->res_heigth = 0;
	vars->res_width = 0;
	while (line[x] >= '0' && line[x] <= '9')
	{
		vars->res_width = (vars->res_width * 10) + (int)line[x] - 48;
		x++;
	}
	x++;
	while (line[x] >= '0' && line[x] <= '9')
	{
		vars->res_heigth = (vars->res_heigth * 10) + (int)line[x] - 48;
		x++;
	}
	return (*vars);
}