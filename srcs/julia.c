/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:04:45 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/02 18:12:29 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_jul_pixel(t_env *env, t_frac frac, int i)
{
	ft_put_pixel(env, frac.x, frac.y, (0x0001e0) * (i + 1));
}

void	ft_draw_jul(t_env *env, t_frac frac)
{
	int		i;
	double 	tmp_zr;

	while (++frac.x < IMG_SIZE)
	{
		frac.y = -1;
		while (++frac.y < IMG_SIZE)
		{
			frac.zr = frac.x / frac.zoom_x + frac.x1;
			frac.zi = frac.y / frac.zoom_y + frac.y1;
			i = -1;
			while ((frac.zr * frac.zr + frac.zi * frac.zi) < 4
				&& ++i < frac.i_max)
			{
				tmp_zr = frac.zr;
				frac.zr = frac.zr * frac.zr - frac.zi * frac.zi + frac.cr;
				frac.zi = 2 * frac.zi * tmp_zr + frac.ci;
			}
			ft_jul_pixel(env, frac, i);
		}
		frac.y = -1;
	}
	ft_expose_hook(env);
}

void	ft_set_julia(t_env *env)
{
	env->frac.x = -1;
	env->frac.y = -1;
	env->frac.x1 = -1;
	env->frac.x2 = 1;
	env->frac.y1 = -1.2;
	env->frac.y2 = 1.2;
	env->frac.cr = 0.285;
	env->frac.ci = 0.01;
	env->frac.i_max = 50;
	env->frac.zoom_x = IMG_SIZE / (env->frac.x2 - env->frac.x1);
	env->frac.zoom_y = IMG_SIZE / (env->frac.y2 - env->frac.y1);
}
