/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:53:33 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/09 15:19:20 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(mem = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) +
					ft_strlen((char *)s2) + 1)))
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strcpy((mem + ft_strlen((char *)s1)), s2);
	return (mem);
}
