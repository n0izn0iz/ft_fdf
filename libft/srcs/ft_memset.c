/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:00:46 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/05 17:19:40 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*byte_array;
	size_t			i;

	byte_array = b;
	i = 0;
	while (i < len)
	{
		byte_array[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
