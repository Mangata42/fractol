/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:13:12 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/07 10:49:30 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_colorwave(t_env *env)
{
	env->frac.cr = (env->mos_x - 250) / 100;
	env->frac.ci = (env->mos_y - 250) / 100;
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, IMG_SIZE, IMG_SIZE);
	ft_choose_frac(env);
}

void	ft_iteration(t_env *env, int keycode)
{
	if (keycode == K_UP)
		env->frac.i_max += 10;
	else
		env->frac.i_max -= 10;
}

void	ft_zoom(t_env *env, int button)
{
	env->frac.x1 += (env->mos_x - 250) / 1000;
	env->frac.x2 += (env->mos_x - 250) / 1000;
	env->frac.y1 += (env->mos_y - 250) / 1000;
	env->frac.y2 += (env->mos_y - 250) / 1000;
	if (button == WHEEL_UP)
	{
		env->frac.zoom_x = env->frac.zoom_x + env->frac.zoom_x * 0.20;
		env->frac.zoom_y = env->frac.zoom_y + env->frac.zoom_y * 0.20;
	}
	if (button == WHEEL_DOWN)
	{
		env->frac.zoom_x = env->frac.zoom_x - env->frac.zoom_x * 0.20;
		env->frac.zoom_y = env->frac.zoom_y - env->frac.zoom_y * 0.20;
	}
}

void	ft_put_pixel(t_env *env, int x, int y, int color)
{
	int 	pos;
	int8_t 	mask;

	if ((x >= 0 && x <= IMG_SIZE) && (y >= 0 && y <= IMG_SIZE))
	{
		pos = (y * env->sl + x * 4);
		mask = color;
		env->img_datas[pos] = mask;
		color = color >> 8;
		mask = color;
		env->img_datas[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->img_datas[pos + 2] = mask;
		env->img_datas[pos + 3] = 0x00;
	}
}
