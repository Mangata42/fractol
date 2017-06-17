/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:43:44 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/17 17:01:39 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "../includes/X11/X.h"
# include <stdint.h>
# include <math.h>

# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define K_SPA 49
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define IMG_SIZE 500

typedef	struct s_env	t_env;
typedef	struct s_frac	t_frac;

struct			s_frac
{
	int			x;
	int			y;
	int			ratio_z;
	int			ratio_d;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		zoom_x;
	double		zoom_y;
	int			i_max;
};

struct			s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_datas;
	int			bpp;
	int			sl;
	int			end;
	int			frac_num;
	int			pause;
	int			pal[5][5];
	int			col_no;
	double		mos_x;
	double		mos_y;
	t_frac		frac;
};

t_env			*init_env(void);
void			ft_errors(int error_code);
void			ft_set_mand(t_env *env);
void			ft_set_julia(t_env *env);
void			ft_draw_mand(t_env *env, t_frac frac);
void			ft_draw_jul(t_env *env, t_frac frac);
void			ft_set_burning(t_env *env);
void			ft_draw_burning(t_env *env, t_frac frac);
void			ft_burning_pixel(t_env *env, t_frac frac, int i);
void			ft_choose_frac(t_env *env);
void			ft_put_pixel(t_env *env, int x, int y, int color);
int				ft_expose_hook(t_env *env);
int				ft_keyhook(int keycode, t_env *env);
int				ft_mouse_click_hook(int button, int x, int y, t_env *env);
int				ft_mouse_mv_hook(int x, int y, t_env *env);
void			ft_zoom(t_env *env, int button);
void			ft_iteration(t_env *env, int keycode);
void			ft_colorwave(t_env *env);
void			ft_color_shades(t_env *env, int keycode);

#endif
