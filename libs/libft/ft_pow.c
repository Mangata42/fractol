/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:22:53 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/12 15:23:01 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int pow)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (i < pow)
	{
		ret = ret * n;
		i++;
	}
	return (ret);
}