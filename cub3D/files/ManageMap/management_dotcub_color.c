/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:02 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/24 22:12:04 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			to_hex(int nb)
{
	int res;

	if (nb > 15)
		res = to_hex(nb / 16);
	if ((nb % 16) == 10)
		res = 0xA;
	else if ((nb % 16) == 11)
		res = 0xB;
	else if ((nb % 16) == 12)
		res = 0xC;
	else if ((nb % 16) == 13)
		res = 0xD;
	else if ((nb % 16) == 14)
		res = 0xE;
	else if ((nb % 16) == 15)
		res = 0xF;
	else
		res = (nb % 16) * 10;
	return (res);
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			dec_to_color_int(int t, int r, int g, int b)
{
	int hex_r;
	int hex_g;
	int hex_b;

	t = 0x0;
	hex_r = 0xDC;
	hex_g = 0x64;
	hex_b = 0x0;
	return (t << 24 | hex_r << 16 | hex_g << 8 | hex_b);
}

int			get_t(int trgb)
{
	return (trgb & (0xFF << 16));
}

int			management_dotcub_color(char *line)
{
	int		x;
	int		r;
	int		g;
	int		b;
	char	**str;

	x = 0;
	while (line[x] < '0' || line[x] > '9')
		x++;
	str = ft_split(line + x, ',');
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (management_dotcub_color_error(r, g, b) == 0)
	{
		if (line[0] == 'F')
			perror("FLOOR COLOR ERROR\n");
		if (line[0] == 'C')
			perror("CEILING COLOR ERROR\n");
		return (0);
	}
	free(str);
	return (create_trgb(0, r, g, b));
}
