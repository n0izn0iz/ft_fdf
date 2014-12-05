/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:26:17 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/07 13:04:39 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;

	s_cast = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == (unsigned char)c)
			return (s_cast + i);
		i++;
	}
	return (NULL);
}
