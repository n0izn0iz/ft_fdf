/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:33:21 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/13 16:59:03 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static t_line_buffer	*find_buffer(int const fd, t_list **listptr)
{
	t_line_buffer	*l_buf;
	t_list			*list;
	t_list			*prev;

	list = *listptr;
	prev = NULL;
	while (list)
	{
		l_buf = (t_line_buffer*)(list->content);
		if (l_buf->fd == fd)
			return (list->content);
		prev = list;
		list = list->next;
	}
	l_buf = malloc(sizeof(t_line_buffer));
	l_buf->fd = fd;
	l_buf->str = NULL;
	if (prev && (prev->next = ft_lstnew(l_buf, sizeof(t_line_buffer))))
		return (prev->next->content);
	*listptr = ft_lstnew(l_buf, sizeof(t_line_buffer));
	free(l_buf);
	if (!*listptr || (prev && !prev->next))
		return (NULL);
	return ((*listptr)->content);
}

static int				check_buffer(char **stbuf, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*stbuf)[i] != '\0')
	{
		if ((*stbuf)[i] == '\n')
		{
			*line = ft_strsub(*stbuf, 0, i);
			tmp = *stbuf;
			*stbuf = ft_strdup((*stbuf) + i + 1);
			free(tmp);
			if (!*line || !*stbuf)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

static int				loop(char *str, char **stbuf, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (*stbuf)
			{
				tmp = ft_strsub(str, 0, i);
				*line = ft_strjoin(*stbuf, tmp);
				ft_strdel(stbuf);
				free(tmp);
			}
			else
				*line = ft_strsub(str, 0, i);
			*stbuf = ft_strdup(str + i + 1);
			if (!*stbuf || !*line)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int						get_next_line(int const fd, char **line)
{
	int				status;
	int				read_bytes;
	char			str[BUFF_SIZE + 1];
	t_line_buffer	*l_buf;
	static t_list	*list = NULL;

	if (fd < 0 || !line)
		return (-1);
	l_buf = find_buffer(fd, &list);
	if (l_buf->str != NULL && (status = check_buffer(&(l_buf->str), line)) != 0)
		return (status);
	while ((read_bytes = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[read_bytes] = '\0';
		if ((status = loop(str, &(l_buf->str), line)))
			return (status);
	}
	if (read_bytes < 0)
		return (-1);
	return (0);
}
