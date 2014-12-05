/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:54:12 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/07 13:18:47 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == (unsigned char)c)
			return ((char*)s + n);
		n--;
	}
	return (NULL);
}
