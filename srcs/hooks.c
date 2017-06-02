/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:24:42 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/02 17:51:10 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_expose_hook(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		ft_mouse_mv_hook(int x, int y, t_env *env)
{
	if ((x <= 500 && x >= 0) && (y <= 500 && y >= 0))
	{
		env->mos_x = x;
		env->mos_y = y;
	}
	if (env->frac_num == 2 && !env->pause)
		ft_colorwave(env);
	return (0);
}

int		ft_mouse_click_hook(int button, int x, int y, t_env *env)
{
	if ((button == WHEEL_UP || button == WHEEL_DOWN))
		ft_zoom(env, button);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, IMG_SIZE, IMG_SIZE);
	ft_choose_frac(env);
	return (0);
}

int		ft_keyhook(int keycode, t_env *env)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == K_UP || keycode == K_DOWN)
		ft_iteration(env, keycode);
	if (keycode == K_SPA)
		(env->pause) ? (env->pause = 0) : (env->pause = 1);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, IMG_SIZE, IMG_SIZE);
	ft_choose_frac(env);
	return (0);
}
