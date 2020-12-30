/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:27:30 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/30 21:00:04 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "keycodes.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../libs/libft/libft.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_map
{
	int			res_width;
	int			res_heigth;
	char		*path_N;
	char		*path_E;
	char		*path_S;
	char		*path_W;
	char		*path_I;
	int			color_floor;
	int			color_ceiling;
	char		**map;
}				t_map;

int				ft_get_next_line(int fd, char **line);
int				ft_printf(const char *str, ...);
t_map			management_dotcub(char *line, t_map map);
t_map			management_dotcub_res(char *line, t_map *map);
char			*management_dotcub_path(char *line);
char			*management_dotcub_path_sprite(char *line);
int				management_dotcub_color(char *line);
char			*management_dotcub_map(char *line);

#endif