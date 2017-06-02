/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:39:57 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/14 20:41:21 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*mem;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(mem = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + len + 1)))
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strncpy((mem + ft_strlen((char *)s1)), s2, len);
	return (mem);
}
