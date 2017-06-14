/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:12 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/14 22:00:32 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandel_pixel(t_env *env, t_frac frac, int i)
{
	int 	shade;
	int		color;

	shade = i / 10;
	color = env->pal[env->col_no][shade];
	if (shade >= 0 && shade <= 4)
		ft_put_pixel(env, frac.x, frac.y, color);
	else
		ft_put_pixel(env, frac.x, frac.y, color - (i * 0x0a0a0a));
	if (i == frac.i_max)
		ft_put_pixel(env, frac.x, frac.y, 0x0);
}

void	ft_draw_mand(t_env *env, t_frac frac)
{
	int		i;
	double	tmp_zr;

	while (++frac.x < IMG_SIZE)
	{
		frac.y = -1;
		while (++frac.y < IMG_SIZE)
		{
			frac.cr = frac.x / frac.zoom_x +frac.x1;
			frac.ci = frac.y / frac.zoom_y +frac.y1;
			frac.zr = frac.x / frac.zoom_x +frac.x1;
			frac.zi = frac.y / frac.zoom_y +frac.y1;
			i = -1;
			while ((frac.zr * frac.zr + frac.zi * frac.zi) < 4
				&& ++i < frac.i_max)
			{
				tmp_zr = frac.zr;
				frac.zr = frac.zr * frac.zr - frac.zi * frac.zi + frac.cr;
				frac.zi = 2 * frac.zi * tmp_zr + frac.ci;
			}
			ft_mandel_pixel(env, frac, i);
		}
		frac.y = -1;
	}
	ft_expose_hook(env);
}

void	ft_set_mand(t_env *env)
{
	env->frac.x = -1;
	env->frac.y = -1;
	env->frac.x1 = -2.1;
	env->frac.x2 = 0.6;
	env->frac.y1 = -1.2;
	env->frac.y2 = 1.2;
	env->frac.i_max = 50;
	env->frac.ratio_z = 0;
	env->frac.ratio_d = 1000;
	env->frac.zoom_x = IMG_SIZE / (env->frac.x2 - env->frac.x1);
	env->frac.zoom_y = IMG_SIZE / (env->frac.y2 - env->frac.y1);
}
