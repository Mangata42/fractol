/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:47:43 by nghaddar          #+#    #+#             */
/*   Updated: 2017/01/24 16:43:26 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void **dst, int size)
{
	char	*ret;
	char	*c_dst;

	if (dst == NULL)
		return (NULL);
	if (*dst == NULL)
	{
		if (!(c_dst = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		c_dst = ft_memset(c_dst, '\0', size);
		return ((void *)c_dst);
	}
	c_dst = *dst;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(c_dst) + size)))
		return (NULL);
	ret = ft_memset(ret, '\0', ft_strlen(c_dst) + size);
	ret = ft_strcpy(ret, c_dst);
	free(c_dst);
	return ((void *)ret);
}
