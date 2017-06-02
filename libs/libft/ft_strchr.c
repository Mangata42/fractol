/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:15:01 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/12 18:55:01 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	l;

	i = 0;
	l = (char)c;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] == l)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
