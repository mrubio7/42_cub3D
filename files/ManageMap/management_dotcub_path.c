/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:38:41 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 12:58:12 by mrubio           ###   ########.fr       */
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
	printf("\n\n>>%s<<\n\n", vars->path_N);
	return (*vars);
}