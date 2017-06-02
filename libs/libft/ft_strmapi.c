/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:58:47 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/09 15:19:48 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mem;

	if (!(s) || f == NULL)
		return (0);
	if (!(mem = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
