/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:38:41 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/23 23:25:08 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		*management_dotcub_path(char *line)
{
	int		x;
	int		z;
	char	*str;

	x = 0;
	while (line[x] != '.')
		x++;
	z = x;
	while (line[x] != '\0')
		x++;
	str = malloc(x - z + 1);
	x = z;
	z = 0;
	while (line[x] != '\0')
		str[z++] = line[x++];
	str[z] = '\0';
	return (str);
}

char		*management_dotcub_path_sprite(char *line)
{
	int		x;
	int		z;
	char	*str;

	x = 0;
	while (line[x] != '.')
		x++;
	z = x;
	while (line[x] != '\0')
		x++;
	str = malloc(x - z + 1);
	x = z;
	z = 0;
	while (line[x] != '\0')
		str[z++] = line[x++];
	str[z] = '\0';
	return (str);
}
