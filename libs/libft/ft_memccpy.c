/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:55:42 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/07 10:57:59 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	dest1 = dst;
	src1 = src;
	i = 0;
	while (i < n)
	{
		dest1[i] = (char)src1[i];
		if (dest1[i] == (const char)c)
			return ((dst + (i + 1)));
		i++;
	}
	return (NULL);
}
