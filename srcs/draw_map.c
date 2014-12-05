/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:27:14 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/29 16:57:32 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"

void	process_point(t_point *point, t_env *env)
{
	if (point->z < 0)
		point->col = col_mix(env->mid_color, env->base_color,
			(float)point->z / (float)env->map->max_depth);
	else if (point->z > 0)
		point->col = col_mix(env->mid_color, env->top_color,
			(float)point->z / (float)env->map->max_height);
	else
		point->col = env->mid_color;
	applypersp(point, 420, 200, env);
}

void	draw_coord(t_env *env, int x, int y)
{
	t_map	*map;
	t_point	point;
	t_point point2;

	map = env->map;
	point = map->lines[y].points[x];
	process_point(&point, env);
	if (x < map->lines[y].size - 1)
	{
		point2 = map->lines[y].points[x + 1];
		process_point(&point2, env);
		plot_line(point, point2, env);
	}
	if (y < map->lines_nbr - 1 && x < map->lines[y + 1].size)
	{
		point2 = map->lines[y + 1].points[x];
		process_point(&point2, env);
		plot_line(point, point2, env);
	}
}

void	draw_map(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->map->lines_nbr)
	{
		x = 0;
		while (x < env->map->lines[y].size)
		{
			draw_coord(env, x, y);
			x++;
		}
		y++;
	}
}
