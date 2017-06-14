/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 11:32:46 by nghaddar          #+#    #+#             */
/*   Updated: 2017/06/14 17:49:17 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		set_pal(t_env *env)
{
	ft_memcpy(env->pal[0], (int[])
		{0x581845, 0x900C3F, 0xC70039, 0xFF5733, 0xFFC300}, sizeof(int) * 5);
	ft_memcpy(env->pal[1], (int[])
		{0x27fdf5, 0xa8f6f8, 0xd7fffe, 0xf98dc9, 0xf765b8}, sizeof(int) * 5);
	ft_memcpy(env->pal[2], (int[])
		{0x6abcfe, 0x1897fd, 0x117dd4, 0x053b67, 0x022038}, sizeof(int) * 5);
	ft_memcpy(env->pal[3], (int[])
		{0x6A0000, 0xc70000, 0xff0000, 0xff5c5c, 0xffd0d0}, sizeof(int) * 5);
	ft_memcpy(env->pal[4], (int[])
		{0x740074, 0xba00ba, 0xff00ff, 0xff5cff, 0xffd0ff}, sizeof(int) * 5);
}

t_env	*init_env(void)
{
	t_env	*env;
	int		pal[5][5];

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
	env->col_no = 0;
	set_pal(env);
	return (env);
}
