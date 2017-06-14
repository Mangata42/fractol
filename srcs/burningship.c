/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:43:52 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/14 23:17:30 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_burning_pixel(t_env *env, t_frac frac, int i)
{
	if (i < frac.i_max)
		ft_put_pixel(env, frac.x, frac.y, (0x0e0000) * (i + 1));
}

void	ft_draw_burning(t_env *env, t_frac frac)
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
			while (pow((fabs(frac.zr) + fabs(frac.zr)), 2) + (frac.cr + frac.ci) < 2
				&& ++i < frac.i_max)
			{
				tmp_zr = frac.zr;
				frac.zr = frac.zr * frac.zr - frac.zi * frac.zi + frac.cr;
				frac.zi = 2 * frac.zi * tmp_zr + frac.ci;
			}
			ft_burning_pixel(env, frac, i);
		}
		frac.y = -1;
	}
	ft_expose_hook(env);
}

void	ft_set_burning(t_env *env)
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
