/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:45:47 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/29 16:12:46 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

#define XKC_ESC 65307
#define XKC_P 112

void	fill_img_data(t_env *env)
{
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_WID, WIN_HEI);
	env->img_data = mlx_get_data_addr(env->mlx_img, &(env->bits_per_pixel),
		&(env->line_size), &(env->endian));
}

int		exposefunc(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	if (env->mlx_img)
		mlx_destroy_image(env->mlx_ptr, env->mlx_img);
	fill_img_data(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
	return (0);
}

int		keyfunc(int keycode, t_env *env)
{
	if (keycode == XKC_ESC)
	{
		mlx_destroy_window(env->mlx_ptr, env->mlx_win);
		free_map(&(env->map));
		exit(0);
	}
	else if (keycode == XKC_P)
	{
		env->persp += 1;
		if (env->persp >= PERSP_NUM)
			env->persp = 0;
		if (env->persp == PERSP_TRI)
			ft_putendl("Trimetric perspective");
		else if (env->persp == PERSP_DIM)
			ft_putendl("Dimetric perspective");
		else if (env->persp == PERSP_ISO)
			ft_putendl("Isometric perspective");
		else if (env->persp == PERSP_ORT)
			ft_putendl("Orthographic perspective");
		exposefunc(env);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc <= 1)
	{
		usage(argv[0]);
		return (-1);
	}
	env.base_color = 0x00FF00;
	env.mid_color = 0x8b4513;
	env.top_color = 0xFFFFFF;
	if (argc > 2)
		parse_opts(&env, argc - 2, argv + 2);
	env.mlx_ptr = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx_ptr, WIN_WID, WIN_HEI, "fdf");
	env.mlx_img = NULL;
	env.map = parse_map(argv[1], 20);
	env.persp = PERSP_ORT;
	ft_putendl("Orthographic perspective");
	mlx_expose_hook(env.mlx_win, exposefunc, &env);
	mlx_key_hook(env.mlx_win, keyfunc, &env);
	mlx_loop(env.mlx_ptr);
	free_map(&(env.map));
	return (0);
}
