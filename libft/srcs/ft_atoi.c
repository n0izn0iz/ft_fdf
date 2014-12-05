/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:11:18 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:40:46 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	ft_pow(int i, int p)
{
	if (p == 0)
		return (1);
	else
		return (ft_pow(i, p - 1) * i);
}

static int	ft_atoui(const char *str)
{
	int i;
	int len;
	int result;

	len = ft_numlen(str);
	i = 0;
	result = 0;
	while (i < len && ft_isdigit(str[i]))
	{
		result += (str[i] - '0') * ft_pow(10, len - 1 - i);
		i++;
	}
	return (result);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	while (*str && is_space(*str))
		str++;
	while (*str && is_sign(*str))
	{
		if (*(str+1) && ft_isdigit(*(str+1)))
			break;
		str++;
	}
	if (*str == '-')
		return (-ft_atoui(str + 1));
	else if (*str == '+')
		return (ft_atoui(str + 1));
	else
		return (ft_atoui(str));
}
