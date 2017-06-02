/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:42:02 by nghaddar          #+#    #+#             */
/*   Updated: 2017/05/19 11:40:07 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_errors(int error_code)
{
	if (error_code == 1)
		ft_putendl("usage: ./fractol {fractal type} (Mandelbrot, Julia)");
	if (error_code == 2)
	{
		ft_putendl("fractal not recognized, the fuck m8");
		ft_errors(1);
	}
	if (error_code == 0)
		ft_putendl("General error");
	exit(EXIT_FAILURE);
}
