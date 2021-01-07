/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_errors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:37:52 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/06 22:53:27 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		management_dotcub_res_error(int width, int heigth)
{
	if (width > 1920 || heigth > 1080)
	{
		ft_printf("RESOLUTION ERROR");
		return (0);
	}
	return (1);
}

int		management_dotcub_color_error(int r, int g, int b)
{
	int x;

	x = 0;
	if (r > 255 || r < 0)
	{
		ft_printf(" - COLOR RED: OUT OF RANGE: %d/255\n", r);
		x++;
	}
	if (g > 255 || g < 0)
	{
		ft_printf(" - COLOR GREEN: OUT OF RANGE: %d/255\n", g);
		x++;
	}
	if (b > 255 || b < 0)
	{
		ft_printf(" - COLOR BLUE: OUT OF RANGE: %d/255\n", b);
		x++;
	}
	if (x > 0)
		return (0);
	return (1);
}

int		management_dotcub_errors(t_map *map)
{
	int r;

	r = 0;
	if ((r += management_dotcub_res_error(map->res_width, map->res_heigth)) == 0)
		return (0);
	if ((r += management_dotcub_closedmap(map->map)) == 0)
		return (0);
	return (1);
}


