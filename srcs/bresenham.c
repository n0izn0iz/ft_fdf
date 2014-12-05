/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:44:59 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/29 16:56:45 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void		plot_dot(int x, int y, int color, t_env *env)
{
	char	*img_data;
	int		*tmp;

	img_data = env->img_data;
	if (x > WIN_WID || x < 0 || y > WIN_HEI || y < 0)
		return ;
	tmp = (int*)(img_data + (x * (env->bits_per_pixel / 8))
		+ (y * env->line_size));
	*tmp = color;
}

static int		swap_quadrant(int *steep, t_point *apt, t_point *bpt)
{
	if ((*steep = (abs(bpt->y - apt->y) > abs(bpt->x - apt->x))))
	{
		ft_swap(&(apt->x), &(apt->y));
		ft_swap(&(bpt->x), &(bpt->y));
	}
	if (apt->x > bpt->x)
	{
		ft_swap(&(apt->x), &(bpt->x));
		ft_swap(&(apt->y), &(bpt->y));
		ft_swap(&(apt->col), &(bpt->col));
	}
	if (apt->y < bpt->y)
		return (1);
	else
		return (-1);
}

static int		prep_vars(t_point *dp, t_point *it, t_point *apt, t_point *bpt)
{
	dp->x = bpt->x - apt->x;
	dp->y = abs(bpt->y - apt->y);
	it->x = apt->x - 1;
	it->y = apt->y;
	return (dp->x / 2);
}

void			plot_line(t_point apt, t_point bpt, t_env *env)
{
	t_point	dp;
	t_point	it;
	t_point	misc;
	float	gain;

	misc.y = swap_quadrant(&(misc.z), &apt, &bpt);
	misc.x = prep_vars(&dp, &it, &apt, &bpt);
	while (++it.x <= bpt.x)
	{
		gain = (float)(it.x - apt.x) / (bpt.x - apt.x);
		if (misc.z)
			plot_dot(it.y, it.x, col_mix(apt.col, bpt.col, gain), env);
		else
			plot_dot(it.x, it.y, col_mix(apt.col, bpt.col, gain), env);
		misc.x -= dp.y;
		if (misc.x < 0)
		{
			it.y += misc.y;
			misc.x += dp.x;
		}
	}
}
