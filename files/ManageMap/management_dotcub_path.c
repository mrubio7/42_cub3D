/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:38:41 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/28 16:55:04 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		*management_dotcub_path(char *line)
{
	int x;
	int z;
	char *str;

	z = 0;
	x = 0;
	while (line[x] != '.')
		x++;
	while (line[x] != '\0')
		x++;
	str = malloc(x - 3);
	x = 3;
	while (line[x] != '\0')
		str[z++] = line[x++];
	str[z] = '\0';
	return (str);
}

char		*management_dotcub_path_sprite(char *line)
{
	int x;
	int z;
	char *str;

	z = 0;
	x = 0;
	while (line[x] != '.')
		x++;
	while (line[x] != '\0')
		x++;
	str = malloc(x - 2);
	x = 2;
	while (line[x] != '\0')
		str[z++] = line[x++];
	str[z] = '\0';
	return (str);
}