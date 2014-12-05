/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:00:00 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/13 15:47:42 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 20000

typedef struct	s_line_buffer
{
	int		fd;
	char	*str;
}				t_line_buffer;

int				get_next_line(int const fd, char **line);

#endif
