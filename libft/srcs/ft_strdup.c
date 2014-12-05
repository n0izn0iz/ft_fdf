/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:48:53 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:45:58 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	char	*result;
	int		len;

	len = ft_strlen(s1);
	result = malloc(sizeof(char) * (len + 1));
	if (result != NULL)
	{
		while (len >= 0)
		{
			result[len] = s1[len];
			len--;
		}
	}
	return (result);
}
