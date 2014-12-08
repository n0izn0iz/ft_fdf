/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:55:51 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/29 15:38:53 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RAD(a) ((a) * (M_PI / 180.f))
# define LAST(k,n) ((k) & ((1<<(n))-1))
# define MID(k,m,n) LAST((k)>>(m),((n)-(m)))

# define WIN_HEI 1200
# define WIN_WID 1200

typedef enum	e_persp_type
{
	PERSP_TRI = 0,
	PERSP_DIM,
	PERSP_ISO,
	PERSP_ORT
}				t_persp_type;
# define PERSP_NUM 4

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		col;
}				t_point;

typedef struct	s_line
{
	int		size;
	t_point	*points;
}				t_line;

typedef struct	s_map
{
	int			max_height;
	int			max_depth;
	int			lines_nbr;
	int			max_line_width;
	float		scale;
	t_line		*lines;
}				t_map;

typedef struct	s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				line_size;
	int				bits_per_pixel;
	int				endian;
	char			*img_data;
	t_persp_type	persp;
	t_map			*map;
	int				base_color;
	int				mid_color;
	int				top_color;
}				t_env;

void			usage(char *pgm_name);
t_map			*parse_map(char *filename, int size);
int				ft_hexstrtoi(char *str);
int				col_mix(int cola, int colb, float gain);
void			parse_opts(t_env *env, int argc, char **argv);
void			free_map(t_map **map);
void			draw_map(t_env *env);
int				splitlen(char **split);
void			plot_line(t_point apt, t_point bpt, t_env *env);
void			applypersp(t_point *point, int xbase,
	int ybase, t_env *env);
int				ft_max(int a, int b);
float			ft_fmax(float a, float b);

#endif
