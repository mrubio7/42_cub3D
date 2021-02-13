/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:03:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/13 17:12:31 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		int_to_chars(int *str, int val)
{
	str[0] = val;
	str[1] = val >> 8;
	str[2] = val >> 16;
	str[3] = val >> 24;
}

int			get_color_bmp(t_all *all, int x, int y)
{
	int color;
	int rgb;

	color = (int)all->vars.win + (all->map.resW * 4 *(all->map.resH - y - 1)) + (x * 4);
	return (color);
}

void		set_pixelsbmp(int fd, t_all *all)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	while (y <= all->map.resH)
	{
		x = 0;
		while (x <= all->map.resW)
		{
			color = get_color_bmp(all, x, y);
			write(1, &color, 3);
			x++;
		}
		y++;
	}
}

void		set_headerbmp(int fd, int size, t_all *all)
{
	int headerbmp[54];
	int x;

	x = 0;
	while (x < 54)
		headerbmp[x++] = 0x00;
	headerbmp[0] = 0x42;
	headerbmp[1] = 0x4D;
	int_to_chars(headerbmp + 2, size);
	headerbmp[10] = 0x36;
	headerbmp[14] = 0x28;
	int_to_chars(headerbmp + 18, all->map.resW);
	int_to_chars(headerbmp + 22, all->map.resH);
	headerbmp[27] = 0x01;
	headerbmp[28] = 0x18;
	write(fd, headerbmp, 54);
}

void		save_bmp(t_all *all)
{
	int			size;
	int			fd;
	int			pad;

	fd = open("screenshot.bmp", O_CREAT);
	pad = all->map.resW % 4;
	size = 54 + (all->map.resW * all->map.resW);
	set_headerbmp(fd, size, all);
	set_pixelsbmp(fd, all);
	close(fd);
}