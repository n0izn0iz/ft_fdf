/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 12:13:52 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/03 12:14:01 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

int			splitlen(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float		ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_hexstrtoi(char *str)
{
	int		len;
	int		i;
	int		result;
	char	c;

	if (*(str++) != '0' || *(str++) != 'x')
		return (0);
	result = 0;
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		c = str[len - i - 1];
			c = ft_toupper(c);
		if (ft_isdigit(c))
			c = (c - '0');
		else if ('A' <= c && c <= 'F')
			c = (c - 'A' + 10);
		else
			c = 0;
		result += (c << (i * 4));
		i++;
	}
	return (result);
}

int			col_mix(int cola, int colb, float gain)
{
	int	rr;
	int	gr;
	int	br;

	rr = (MID(cola, 16, 24) * (1 - gain)) + (MID(colb, 16, 24) * gain);
	gr = (MID(cola, 8, 16) * (1 - gain)) + (MID(colb, 8, 16) * gain);
	br = (MID(cola, 0, 8) * (1 - gain)) + (MID(colb, 0, 8) * gain);
	rr = rr << 16;
	gr = gr << 8;
	return (rr + gr + br);
}
