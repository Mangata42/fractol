/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:18:53 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/17 14:29:14 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_check_args(char *frac_name, t_env *env)
{
	if (ft_strcmp(frac_name, "mandelbrot") == 0)
	{
		env->frac_num = 1;
		ft_set_mand(env);
	}
	else if (ft_strcmp(frac_name, "julia") == 0)
	{
		env->frac_num = 2;
		ft_set_julia(env);
	}
	else if (ft_strcmp(frac_name, "burningship") == 0)
	{
		env->frac_num = 3;
		ft_set_burning(env);
	}
	else
		ft_errors(2);
}

void		ft_choose_frac(t_env *env)
{
	if (env->frac_num == 1)
		ft_draw_mand(env, env->frac);
	if (env->frac_num == 2)
		ft_draw_jul(env, env->frac);
	if (env->frac_num == 3)
		ft_draw_burning(env, env->frac);
}

int			main(int argc, char **argv)
{
	t_env *env;

	env = init_env();
	if (argc != 2)
		ft_errors(1);
	ft_check_args(argv[1], env);
	ft_choose_frac(env);
	mlx_mouse_hook(env->win, ft_mouse_click_hook, env);
	mlx_key_hook(env->win, ft_keyhook, env);
	mlx_expose_hook(env->win, ft_expose_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, ft_mouse_mv_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
