/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:54:22 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/07 15:55:41 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int		num_pr_sp(char const *s)
{
	int i;

	i = 0;
	while (is_whitespace(s[i]))
		i++;
	return (i);
}

static int		num_tr_sp(char const *s)
{
	int i;
	int j;

	i = ft_strlen(s) - 1;
	j = 0;
	while (is_whitespace(s[i]))
	{
		j++;
		i--;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	int pr_sp;
	int tr_sp;
	int len;

	if (!s)
		return (NULL);
	pr_sp = num_pr_sp(s);
	tr_sp = num_tr_sp(s);
	len = ft_strlen(s);
	if (pr_sp == len)
		return (ft_strnew(0));
	return (ft_strsub(s, pr_sp, len - tr_sp - pr_sp));
}
