/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:57:25 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/03 12:14:29 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

static int		filetolist(char *filename, t_list *lst)
{
	int		lines_count;
	int		fd;
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		lines_count++;
		split = ft_strsplitnbrs(line);
		free(line);
		lst->content = split;
		lst->content_size = sizeof(char**);
		lst->next = ft_lstnew(NULL, 0);
		lst = lst->next;
	}
	close(fd);
	return (lines_count);
}

static int		process_split(t_list *lst, t_map *map, int y, int size)
{
	char	**split;
	int		x;
	t_point	*point;

	split = (char**)lst->content;
	map->lines[y].size = splitlen(split);
	map->lines[y].points = (t_point*)malloc(sizeof(t_point)
		* (map->lines[y].size + 1));
	x = 0;
	while (x < map->lines[y].size)
	{
		point = &(map->lines[y].points[x]);
		point->x = x * size;
		point->y = y * size;
		point->z = ft_atoi(split[x]) / 10.f * size;
		if (map->max_height < point->z)
			map->max_height = point->z;
		if (map->max_depth > point->z)
			map->max_depth = point->z;
		free(split[x]);
		x++;
	}
	free(split);
	return (map->lines[y].size);
}

static void		fillmap(t_list *lst, t_map *map, int size)
{
	int		y;

	map->lines = (t_line*)malloc(sizeof(t_line) * (map->lines_nbr + 1));
	y = 0;
	if (lst != NULL)
	{
		map->max_height = ft_atoi(((char**)lst->content)[0]);
		map->max_depth = ft_atoi(((char**)lst->content)[0]);
	}
	while (lst != NULL && y < map->lines_nbr)
	{
		map->max_line_width = ft_max(map->max_line_width, process_split(lst, map, y, size));
		y++;
		lst = lst->next;
	}
	map->scale = ft_fmax((WIN_WID / (float)((map->max_line_width) * size)), WIN_HEI / (float)((map->lines_nbr) * size));
}

t_map			*parse_map(char *filename, int size)
{
	t_map	*map;
	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew(NULL, 0);
	map = (t_map*)malloc(sizeof(t_map));
	map->lines_nbr = filetolist(filename, lst);
	fillmap(lst, map, size);
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (map);
}

void			free_map(t_map **map)
{
	int y;

	if (*map == NULL)
		return ;
	y = 0;
	while (y < (*map)->lines_nbr)
	{
		free((*map)->lines[y].points);
		y++;
	}
	free((*map)->lines);
	free(*map);
	*map = NULL;
}
