/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:27:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/01/19 18:46:17 by mrubio           ###   ########.fr       */
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

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_pj
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
}				t_pj;

typedef struct	s_ray
{
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			mapX;
	int			mapY;
	int			side;
	int			hit;
}				t_ray;

typedef struct	s_game
{
	double		perpWallDist;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			color;
}				t_game;


typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

int				ft_get_next_line(int fd, char **line);
int				ft_printf(const char *str, ...);

t_map			management_dotcub(char *line, t_map map);
t_map			management_dotcub_res(char *line, t_map *map);
char			*management_dotcub_path(char *line);
char			*management_dotcub_path_sprite(char *line);
int				management_dotcub_color(char *line);
char			*management_dotcub_map(char *line);
int				management_dotcub_errors(t_map *map, t_vars *vars);
int				management_dotcub_color_error(int r, int g, int b);
int				management_dotcub_closedmap(char **map);

int				init_game(t_map map, t_vars vars);
t_pj			detect_start_pos(char **map, t_pj pj);
int				loop_frame(t_vars *vars, t_map *map, t_pj *pj, t_game game, t_img *img);
int				v_line(t_vars *vars, t_pj *pj, t_game *game, t_map *map, t_img *img, int z);
int				get_color_wall(t_ray *ray, char **map);
void			put_pixels(t_vars *vars, t_game *game, t_img *img, int z, int res);
int				movement_pj(int keycode, t_pj *pj);

#endif