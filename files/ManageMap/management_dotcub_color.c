/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:02 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/29 16:29:59 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			management_dotcub_color(char *line)
{
	int x;
	int r;
	int g;
	int b;
	char **str;

	x = 0;
	while (line[x] < '0' || line[x] > '9')
		x++;
	str = ft_strsplit(line + x, ',');
	r = atoi(str[0]);
	g = atoi(str[1]);
	b = atoi(str[2]);
	printf("\n>r:%d, g:%d, b:%d<\n", r, g, b);
	return (0);
}
