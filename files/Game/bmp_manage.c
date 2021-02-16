/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:31:28 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/13 20:46:21 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			bmp_manage(char *str)
{
	int bmp;
	int x;

	x = 0;
	while (str[x] == ' ' || str[x] == '\t')
		x++;
	bmp = ft_strncmp("--save", str + x, 6);
	if (bmp == 0)
		return (1);
	return (0);
}
