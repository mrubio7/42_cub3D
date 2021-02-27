/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:27:30 by mrubio            #+#    #+#             */
/*   Updated: 2021/02/27 11:48:56 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SIZE_WIDTH 100
# define SIZE_HEIGHT 100
# define NUMSPRITES 5
# include "../libs/minilibx_macos/mlx.h"
# include "../libs/libft/libft.h"
# include "keycod.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_map
{
	int			error;
	int			r;
	int			n;
	int			s;
	int			e;
	int			w;
	int			i;
	int			f;
	int			c;
	int			resw;
	int			resh;
	char		*path_n;
	char		*path_e;
	char		*path_s;
	char		*path_w;
	char		*path_i;
	int			color_f;
	int			color_c;
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
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
}				t_pj;

typedef struct	s_ray
{
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	int			side;
	int			hit;
	int			sprite;
}				t_ray;

typedef struct	s_game
{
	double		perpwalldist;
	int			lineh;
	int			drawst;
	int			drawen;
	int			color;
}				t_game;

typedef struct	s_spr
{
	int			*zbuffer;
	double		*sp_dis;
	double		spx;
	double		spy;
	double		invdet;
	double		transformx;
	double		transformy;
	int			sp_screenx;
	int			sph;
	int			spw;
	int			drawsty;
	int			drawstx;
	int			draweny;
	int			drawenx;
	int			*sp_ord;
}				t_spr;

typedef struct	s_wtex
{
	int			texnum;
	double		wallx;
	double		texstep;
	double		texpos;
	int			texx;
	int			texy;
	uint32_t	*buff;
	int			texh;
	int			texw;
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
	int			bmp;
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
void			management_dotcub(char *line, t_map *map);
void			management_dotcub_res(char *line, t_map *map);
char			*management_dotcub_path(char *line);
char			*management_dotcub_path_sprite(char *line);
int				management_dotcub_color(char *line);
char			*management_dotcub_map(char *line);
int				management_dotcub_errors(t_map *map, t_vars *vars);
int				management_dotcub_color_error(int r, int g, int b);
int				management_dotcub_closedmap(char **map);
void			management_duplicated(t_map *map);
void			read_dotcub_error(t_map *map, char *line);
int				read_dotcub(t_all *all, char *argv);
int				save_bmp(t_all *all);
int				init_game(t_all *all);
t_pj			detect_start_pos(char **map, t_pj pj);
int				loop_frame(t_all *all);
int				v_line(t_all *all, int z);
int				load_textures(t_all *all);
void			texture_line(t_all *all, int z);
int				movement_pj(int keycode, t_all *all);
void			move_left(t_pj *pj, t_map *map);
void			move_right(t_pj *pj, t_map *map);
double			next_move(double pos, double step);
void			put_pixels(t_all *all, int z);
void			move_left(t_pj *pj, t_map *map);
int				get_color_from_addr(t_all *all, int n);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
void			get_sprites(t_all *all);
void			init_sprites(t_all *all);
void			put_sprites(t_all *all, int z);
void			draw_sprite(t_all *all, int x);
void			free_game(t_all *all);

#endif
