/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:58:00 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 13:47:45 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAP_W 0
# define MAP_H 1
# define ST_X 2
# define ST_Y 3
# define ST_DIR 4
# define N_SPRT 5
# define TRAP 5
# define MEDP 6
# define EXIT 7

typedef	struct	s_pars
{
	char		*line;
	int			parsedresol;
	int			parsedtex[5][4];
	int			parsedsprt[8];
	int			parsedfloor;
	int			parsedceiling;
	int			retgnl;
	int			clr_f;
	int			fr;
	int			fg;
	int			fb;
	int			clr_c;
	int			cr;
	int			cg;
	int			cb;
	int			parsingmap;
	char		*strmap;
}				t_pars;

typedef	struct	s_maps
{
	int			nbrmaps;
	int			***tabmaps;
	int			**tabmapval;
	int			sizemapx;
	int			sizemapy;
	int			startset;
}				t_maps;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			img_bpp;
	int			img_sl;
	int			img_end;
}				t_mlx;

typedef	struct	s_tex
{
	char		*pathtex[5][4];
	void		*tex_ptr[5][4];
	int			*tex_data[5][4];
	int			tex_bpp[5][4];
	int			tex_sl[5][4];
	int			tex_end[5][4];
	int			tex_w[5][4];
	int			tex_h[5][4];
	int			texx;
	int			texy;
	double		texstep;
	double		texpos;
}				t_tex;

typedef	struct	s_sprt
{
	char		*pathsprt[8];
	void		*sprt_ptr[8];
	int			*sprt_data[8];
	int			sprt_bpp[8];
	int			sprt_sl[8];
	int			sprt_end[8];
	int			sprt_w[8];
	int			sprt_h[8];
	double		**tabsprtposx;
	double		**tabsprtposy;
	int			**tabsprttype;
	double		**tabsprtdist;
	int			**tabsprtorder;
	double		transformx;
	double		transformy;
	int			sprtscreenw;
	int			sprtscreenh;
	int			sprtscreenx;
	int			drawstartx;
	int			drawendx;
	int			drawstarty;
	int			drawendy;
	int			stripe;
	int			sprtx;
	int			sprty;
}				t_sprt;

typedef	struct	s_win
{
	int			winw;
	int			winh;
	int			winx;
	int			winy;
}				t_win;

typedef	struct	s_coor
{
	int			currlvl;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		olddirx;
}				t_coor;

typedef	struct	s_spd
{
	double		movespeed;
	double		rotspeed;
}				t_spd;

typedef	struct	s_rayc
{
	double		planex;
	double		planey;
	double		oldplanex;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
}				t_rayc;

typedef	struct	s_wall
{
	int			hit;
	int			side;
	double		walldist;
	double		*tabwalldist;
	double		wallx;
}				t_wall;

typedef	struct	s_draw
{
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
}				t_draw;

typedef	struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			up;
	int			down;
	int			left;
	int			right;
	int			plus;
	int			keepplus;
	int			minus;
	int			keepminus;
	int			esc;
}				t_keys;

typedef	struct	s_st
{
	t_pars		pars;
	t_maps		maps;
	t_mlx		mlx;
	t_tex		tex;
	t_sprt		sprt;
	t_win		win;
	t_coor		coor;
	t_spd		spd;
	t_rayc		rayc;
	t_wall		wall;
	t_draw		draw;
	t_keys		keys;
}				t_st;

int				main(int argc, char **argv);
int				ft_loophook(t_st *st);
int				ft_closewin(t_st *st);

int				get_next_line(int fd, char **line);
int				ft_iswall(int i);
int				ft_issprite(int i);
int				ft_iswalkable(int i);
int				ft_wallisvalid(t_st *st, int j);
int				ft_spriteisvalid(t_st *st, int j);
void			ft_lvlinit(t_st *st);

void			ft_varinit(t_st *st);
void			ft_varinit_pars(t_st *st);
void			ft_varinit_pars_parsedtexloop(t_st *st);
void			ft_varinit_pars_parsedsprtloop(t_st *st);
void			ft_varinit_maps(t_st *st);
void			ft_varinit_mlx(t_st *st);
void			ft_varinit_tex(t_st *st);
void			ft_varinit_tex_loop(t_st *st, int j);
void			ft_varinit_sprt(t_st *st);
void			ft_varinit_sprt_loop(t_st *st);
void			ft_varinit_win(t_st *st);
void			ft_varinit_coor(t_st *st);
void			ft_varinit_spd(t_st *st);
void			ft_varinit_rayc(t_st *st);
void			ft_varinit_wall(t_st *st);
void			ft_varinit_draw(t_st *st);
void			ft_varinit_keys(t_st *st);

void			ft_parsearg(t_st *st, char *arg);
void			ft_parsearg_checkarg(t_st *st, char *arg);
void			ft_parsearg_fileread(t_st *st, char *line);
void			ft_parsearg_fileread_id(t_st *st, char *line);
void			ft_parsearg_fileread_spacechar(t_st *st, char *line);
void			ft_parsearg_fileread_map(t_st *st, char *line);
void			ft_parsearg_resol(t_st *st, char *line);
void			ft_parsearg_resol_getvalue(t_st *st, char **line, char xy);
void			ft_parsearg_tex(t_st *st, char *line);
void			ft_parsearg_tex_path(t_st *st, char *line, int j);
void			ft_parsearg_sprt(t_st *st, char *line, int i);
void			ft_parsearg_sprt_path(t_st *st, char *line, int i);
char			*ft_parsearg_getpath(t_st *st, char *line);
void			ft_parsearg_floor(t_st *st, char *line);
void			ft_parsearg_floor_color(t_st *st, char **line);
int				ft_parsearg_floor_getvalue(t_st *st, char **line);
void			ft_parsearg_ceiling(t_st *st, char *line);
void			ft_parsearg_ceiling_color(t_st *st, char **line);
int				ft_parsearg_ceiling_getvalue(t_st *st, char **line);
void			ft_parsearg_mapread(t_st *st, char *line);
void			ft_parsearg_mapread_strmapinit(t_st *st, char *line);
void			ft_parsearg_mapread_strmapupdate(t_st *st, char *line);
char			*ft_parsearg_mapread_mapline(char *line);
int				ft_parsearg_mapread_sizemapline(char *line);
void			ft_parsearg_mapinit(t_st *st);
int				**ft_parsearg_mapinit_map(t_st *st);
void			ft_parsearg_mapinit_sizemapy(t_st *st);
int				*ft_parsearg_mapinit_mapline(t_st *st, int linenbr, int i);
void			ft_parsearg_mapvalinit(t_st *st);
void			ft_parsearg_mapvalinit_val(t_st *st);
void			ft_parsearg_mapvalid(t_st *st);
void			ft_parsearg_mapvalid_closingline(t_st *st, int j);
void			ft_parsearg_mapvalid_midlines(t_st *st, int *j);
void			ft_parsearg_mapvalid_checktile(t_st *st, int x, int y, int i);
void			ft_parsearg_mapvalid_startval(t_st *st, int x, int y, int i);

void			ft_tabinit(t_st *st);
void			ft_tabinit_gettex(t_st *st);
void			ft_tabinit_gettex_ptrinit(t_st *st, int j);
void			ft_tabinit_gettex_datainit(t_st *st, int j);
void			ft_tabinit_getsprt(t_st *st);
void			ft_tabinit_getsprt_ptrinit(t_st *st, int i);
void			ft_tabinit_getsprt_datainit(t_st *st, int i);
void			ft_tabinit_distandorder(t_st *st);
void			ft_tabinit_distandorder_walldist(t_st *st);
void			ft_tabinit_distandorder_sprtdist(t_st *st);
void			ft_tabinit_distandorder_sprtorder(t_st *st);
void			ft_tabinit_sprtval(t_st *st);
void			ft_tabinit_sprtval_sprtposx(t_st *st);
void			ft_tabinit_sprtval_sprtposy(t_st *st);
void			ft_tabinit_sprtval_sprttype(t_st *st);
void			ft_tabinit_getsprtval(t_st *st);
void			ft_tabinit_getsprtval_loop(t_st *st, int j, int k, int *l);

void			ft_rayc(t_st *st);
void			ft_rayc_ceiling(t_st *st);
void			ft_rayc_floor(t_st *st);
void			ft_rayc_walls(t_st *st);
void			ft_rayc_walls_ray(t_st *st);
void			ft_rayc_walls_step(t_st *st);
void			ft_rayc_walls_dda(t_st *st);
void			ft_rayc_walls_calculate(t_st *st);
void			ft_rayc_drawwalls(t_st *st);
void			ft_rayc_drawwalls_loop(t_st *st, int side);
void			ft_rayc_sprt(t_st *st);
void			ft_rayc_sprt_sortsprt(int *order, double *dist, int amount);
void			ft_rayc_sprt_drawloop(t_st *st);
void			ft_rayc_sprt_varinit(t_st *st, int i);
void			ft_rayc_sprt_stripeloop(t_st *st);

void			ft_keys(t_st *st);
int				ft_keys_keypress(int key, t_st *st);
void			ft_keys_keypress_directions(int key, t_st *st);
void			ft_keys_keypress_various(int key, t_st *st);
int				ft_keys_keyrelease(int key, t_st *st);
void			ft_keys_keyrelease_directions(int key, t_st *st);
void			ft_keys_keyrelease_various(int key, t_st *st);
void			ft_keys_movefwd(t_st *st);
void			ft_keys_movebwd(t_st *st);
void			ft_keys_moveleft(t_st *st);
void			ft_keys_moveright(t_st *st);
void			ft_keys_rotationleft(t_st *st);
void			ft_keys_rotationright(t_st *st);
void			ft_keys_lvlplus(t_st *st);
void			ft_keys_lvlminus(t_st *st);

void			ft_save(t_st *st, char **argv);
void			ft_save_screenshot(t_st *st);
void			ft_save_writedata(t_st *st, int fd);
void			ft_save_writeend(int fd, int val);
void			ft_save_writebmp(t_st *st, int fd, int lsize);
void			ft_save_writebmp_color(int fd, int color);
void			ft_save_writebmp_int(int fd, int val);
void			ft_save_writebmp_halfint(int fd, int val);

void			ft_error(t_st *st, int id);

void			ft_exit(t_st *st, int ret);
int				ft_exit_killmlx(t_st *st);
void			ft_free(t_st *st);
void			ft_free_pars(t_st *st);
void			ft_free_maps(t_st *st);
void			ft_free_maps_tabmaps(t_st *st);
void			ft_free_maps_tabmapval(t_st *st);
void			ft_free_tex(t_st *st);
void			ft_free_tex_pathtex(t_st *st);
void			ft_free_sprt(t_st *st);
void			ft_free_sprt_pathsprt(t_st *st);
void			ft_free_sprt_pos(t_st *st);
void			ft_free_sprt_type(t_st *st);
void			ft_free_sprt_distandorder(t_st *st);

#endif
