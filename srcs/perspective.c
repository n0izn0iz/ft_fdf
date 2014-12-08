/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 10:38:48 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/29 16:57:46 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void		translation(t_point *point, int x, int y)
{
	point->x += x;
	point->y += y;
}

void		scale(t_point *point, float scale)
{
	point->x *= scale;
	point->y *= scale;
	point->z *= scale;
}

void		par_persp(t_point *point, float w, float a)
{
	int x;

	x = point->x;
	point->x = (cos(w) * x) - (sin(w) * point->y);
	point->y = (sin(w) * sin(a) * x) + (cos(w) * sin(a) * point->y) -
		(cos(a) * point->z);
}

void		applypersp(t_point *point, int xbase, int ybase, t_env *env)
{
	if (env->persp == PERSP_TRI)
		par_persp(point, RAD(30.f), RAD(45.f));
	else if (env->persp == PERSP_DIM)
		par_persp(point, RAD(45.f), RAD(45.f));
	else if (env->persp == PERSP_ISO)
		par_persp(point, RAD(45.f), asin(tan(RAD(30.f))));
	if (!(env->persp == PERSP_ORT))
	{
		scale(point, env->map->scale / 2.f);
		translation(point, xbase, ybase);
	}
	else
		scale(point, env->map->scale);
}
