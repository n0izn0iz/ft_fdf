/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:32:45 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:22:37 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *first;

	first = NULL;
	if (lst)
	{
		new_lst = f(lst);
		first = new_lst;
		lst = lst->next;
	}
	while (lst)
	{
		new_lst->next = f(lst);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (first);
}
