/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:17:48 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/27 13:00:16 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vars		management_dotcub(char *line, t_vars vars)
{
	if (line[0] == 'R')
		vars = management_dotcub_res(line, &vars);
	else if (line[0] == 'N' && line[1] == 'O')
		vars = management_dotcub_path_no(line, &vars);
	else if (line[0] == 'S' && line[1] == 'O')
		vars = management_dotcub_path_so(line, &vars);
	else if (line[0] == 'W' && line[1] == 'E')
		vars = management_dotcub_path_we(line, &vars);
	else if (line[0] == 'E' && line[1] == 'A')
		vars = management_dotcub_path_ea(line, &vars);
	else if (line[0] == 'S' && line[1] == ' ')
		vars = management_dotcub_path_sprite(line, &vars);
	return (vars);
}
