/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:43:55 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/14 12:17:01 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (little[y] == big[i] && i < len)
		{
			i++;
			y++;
			if (y == ft_strlen(little))
				return ((char *)big + (i - y));
		}
		i = (i - y) + 1;
		y = 0;
	}
	return (NULL);
}
