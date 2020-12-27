/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:38:41 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:37:05 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vars			management_dotcub_path_no(char *line, t_vars *vars)
{
	int x;
	int z;

	z = 0;
	x = 3;
	while (line[x] != '\0')
		x++;
	vars->path_N = malloc(x - 3);
	x = 3;
	while (line[x] != '\0')
		vars->path_N[z++] = line[x++];
	vars->path_N[z] = '\0';
	return (*vars);
}

t_vars			management_dotcub_path_so(char *line, t_vars *vars)
{
	int x;
	int z;

	z = 0;
	x = 3;
	while (line[x] != '\0')
		x++;
	vars->path_S = malloc(x - 3);
	x = 3;
	while (line[x] != '\0')
		vars->path_S[z++] = line[x++];
	vars->path_S[z] = '\0';
	return (*vars);
}

t_vars			management_dotcub_path_we(char *line, t_vars *vars)
{
	int x;
	int z;

	z = 0;
	x = 3;
	while (line[x] != '\0')
		x++;
	vars->path_W = malloc(x - 3);
	x = 3;
	while (line[x] != '\0')
		vars->path_W[z++] = line[x++];
	vars->path_W[z] = '\0';
	return (*vars);
}
