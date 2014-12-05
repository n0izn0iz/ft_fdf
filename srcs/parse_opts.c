/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:05:11 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/03 13:05:16 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	usage(char *pgm_name)
{
	ft_putendl_fd("Usage: ", 2);
	ft_putstr_fd(pgm_name, 2);
	ft_putendl_fd(" filename [-c base_color mid_color top_color]", 2);
}

void	parse_opts(t_env *env, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i + 3 < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'c')
		{
			env->base_color = ft_hexstrtoi(argv[i + 1]);
			env->mid_color = ft_hexstrtoi(argv[i + 2]);
			env->top_color = ft_hexstrtoi(argv[i + 3]);
			return ;
		}
		i++;
	}
	usage(argv[0]);
}
