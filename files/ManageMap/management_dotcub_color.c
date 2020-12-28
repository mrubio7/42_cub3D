/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_dotcub_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:02 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/28 21:11:22 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			to_hex(int n)
{
	int hex;

	hex = 0;
	if (n > 15)
		hex = to_hex(n / 16);
	if (hex == 0)
		hex = (n % 16) * 100;
	else
		hex = (n % 16) * 10;
	return (hex);
}

int			str_color_to_int_hex(char *red, char *green, char *blue)
{
	int r;
	int g;
	int b;
	int r_hex;
	int g_hex;
	int b_hex;
	int t;

	t = 0x00;
	r = atoi(red);
	g = atoi(green);
	b = atoi(blue);
	r_hex = to_hex(r);
	g_hex = to_hex(g);
	b_hex = to_hex(b);
	return (t << 24 | r_hex << 16 | g_hex << 8 | b_hex);
}

int			management_dotcub_color(char *line)
{
	int x;
	int z;
	char *r;
	char *g;
	char *b;

	r = malloc(4);
	g = malloc(4);
	b = malloc(4);
	x = 0;
	z = 0;
	while (line[x] < '0' || line[x] > '9')
		x++;
	while (line[x] != ',' && line[x] != '\0')
		r[z++] = line[x++];
	z = 0;
	while (line[x] != ',' && line[x] != '\0')
		g[z++] = line[x++];
	z = 0;
	while (line[x] != ',' && line[x] != '\0')
		b[z++] = line[x++];
	free(r);
	free(g);
	free(b);
	return (str_color_to_int_hex(r, g ,b));
}
