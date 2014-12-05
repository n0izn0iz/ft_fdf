/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:37 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/05 17:19:20 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		temp[len];
	const unsigned char	*src_cast;
	unsigned char		*dst_cast;

	src_cast = src;
	dst_cast = dst;
	i = 0;
	while (i < len)
	{
		temp[i] = src_cast[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst_cast[i] = temp[i];
		i++;
	}
	return (dst);
}
