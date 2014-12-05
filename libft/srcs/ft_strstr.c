/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:59:06 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:47:11 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int s2_len;

	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == s2_len - 1)
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
