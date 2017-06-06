/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 11:32:46 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/06 17:31:13 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_env	*init_env(void)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_errors(3);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, IMG_SIZE, IMG_SIZE, "fractlol");
	env->img = mlx_new_image(env->mlx, IMG_SIZE, IMG_SIZE);
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl),
		&(env->end));
	if (!env->mlx || !env->win || !env->img)
		ft_errors(3);
	env->pause = 1;
	return (env);
}
