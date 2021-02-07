/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:27:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/07 17:19:17 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define size_width 100
#define size_height 100
#define numSprites 5

#include "../libs/minilibx_macos/mlx.h"
#include "../libs/libft/libft.h"
#include "keycodes.h"
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_map
{
	int			resW;
	int			resH;
	char		*path_N; //malloc & free
	char		*path_E; //malloc & free
	char		*path_S; //malloc & free
	char		*path_W; //malloc & free
	char		*path_I; //malloc & free
	int			color_f;
	int			color_c;
	char		**map; //malloc & free
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_tximg
{
	void		*tx;
	char		*tx_addr;
	int			tx_bpp;
	int			tx_ll;
	int			tx_endian;
	int			width;
	int			height;
}				t_tximg;

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
	int			sprite;
}				t_ray;

typedef struct	s_game
{
	double		perpWallDist;
	int			lineH;
	int			drawSt;
	int			drawEn;
	int			color;
}				t_game;

typedef struct	s_spr
{
	int			*zbuffer;
	double		*sp_dis;
	double		spX;
	double		spY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			sp_screenX;
	int			spH;
	int			spW;
	int			drawStY;
	int			drawStX;
	int			drawEnY;
	int			drawEnX;
	int			*sp_ord;
	uint32_t	*buff; //malloc
}				t_spr;

typedef struct	s_wtex
{
	int			texNum;
	double		wallX;
	double		texStep;
	double		texPos;
	int			texX;
	int			texY;
	uint32_t	*buff; //malloc
	int			texH;
	int			texW;
}				t_wtex;

typedef struct	s_spos
{
	double		x;
	double		y;
	int			tex;
}				t_spos;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_all
{
	t_vars		vars;
	t_pj		pj;
	t_game		game;
	t_ray		ray;
	t_img		img;
	t_map		map;
	t_wtex		wtex;
	t_tximg		*tximg;
	t_spr		spr;
	t_spos		*spos;
}				t_all;

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

int				init_game(t_all all);
t_pj			detect_start_pos(char **map, t_pj pj);
int				loop_frame(t_all *all);
int				v_line(t_all *all, int z);
int				load_textures(t_all *all);
void			texture_line(t_all *all, int z);
int				movement_pj(int keycode, t_all *all);
double			next_move(double pos, double step);
void			put_pixels(t_all *all, int z);

int				get_color_from_addr(t_all *all, int n);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);

void			get_sprites(t_all *all, int z);
void			init_sprites(t_all *all);
void			put_sprites(t_all *all, int z);
void			draw_sprite(t_all *all, int x);

#endif