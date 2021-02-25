/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:03:19 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/25 21:09:53 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	div_int_to_chars(unsigned char *div, int val)
{
	div[0] = (unsigned char)(val);
	div[1] = (unsigned char)(val >> 8);
	div[2] = (unsigned char)(val >> 16);
	div[3] = (unsigned char)(val >> 24);
}

int		get_color(t_all *all, int x, int y, int pad)
{
	int				pos;
	unsigned int	color;
	int				octs;
	int				i;
	int				o;

	color = 0;
	i = 0;
	o = 24;
	octs = all->img.bits_per_pixel / 8;
	pos = (all->img.line_length * y) + (octs * x);
	color += all->img.addr[pos] << (0);
	color += all->img.addr[pos + 1] << (8);
	color += all->img.addr[pos + 2] << (16);
	color += all->img.addr[pos + 3] << (24);
	return (color);
}

int		bmp_header(int fd, t_map *map, int nbpr, int pad)
{
	unsigned char	head[54];
	unsigned int	*size;
	unsigned int	*wid;
	unsigned int	*hei;

	ft_bzero(head, 54);
	head[0] = (unsigned int)('B');
	head[1] = (unsigned int)('M');
	head[10] = (unsigned int)(54);
	head[14] = (unsigned int)(40);
	head[26] = (unsigned int)(1);
	head[28] = (unsigned int)(24);
	size = (unsigned int *)&head[2];
	wid = (unsigned int *)&head[18];
	hei = (unsigned int *)&head[22];
	*size = 54 + (nbpr + pad) * map->resh;
	*wid = map->resw;
	*hei = map->resh;
	return (!(write(fd, head, 54) < 0));
}

int		bmp_pix(int fd, t_all *all, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = all->map.resh - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < all->map.resw)
		{
			pixel = get_color(all, x, y, padsize);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int		save_bmp(t_all *all)
{
	int		padsize;
	int		fd;
	int		nbpr;

	loop_frame(all);
	nbpr = all->map.resw * (all->img.bits_per_pixel / 8);
	padsize = (nbpr - 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666 |
									O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, &all->map, nbpr, padsize);
	bmp_pix(fd, all, padsize);
	close(fd);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	free_game(all);
	write(1, "\"screenshot.bmp\" saved!\n", 24);
	exit(0);
}
