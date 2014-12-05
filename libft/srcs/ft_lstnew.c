/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:50:29 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:43:18 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	if (lst)
	{
		if (content == NULL)
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		else
		{
			lst->content = malloc(content_size);
			if (!lst->content)
				return (NULL);
			lst->content = ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
		lst->next = NULL;
	}
	return (lst);
}
