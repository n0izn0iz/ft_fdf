/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:28:05 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:47:04 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strnew(size_t size)
{
	char *result;

	result = malloc(size + 1);
	if (result != NULL)
		ft_bzero(result, size + 1);
	return (result);
}
