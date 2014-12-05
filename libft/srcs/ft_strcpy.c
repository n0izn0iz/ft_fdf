/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:46:16 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/05 14:53:14 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *dst, const char *src)
{
	char *dst_save;

	dst_save = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = *src;
	return (dst_save);
}
