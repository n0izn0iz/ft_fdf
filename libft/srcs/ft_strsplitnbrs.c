/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:09:57 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/27 16:11:26 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_delim(char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

static int	get_words_number(char const *s)
{
	int result;
	int in_word;

	result = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!in_word && is_delim(*s))
		{
			in_word = 1;
			result++;
		}
		if (in_word && !is_delim(*s))
		{
			in_word = 0;
		}
		s++;
	}
	return (result);
}

static int	get_word_len(char const *s)
{
	int i;

	i = 0;
	while (is_delim(s[i]) && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplitnbrs(char const *s)
{
	int		words_nbr;
	char	**result;
	int		word_len;
	int		i;

	if (!s)
		return (NULL);
	words_nbr = get_words_number(s);
	result = (char**)malloc(sizeof(char*) * (words_nbr + 1));
	if (result != NULL)
	{
		i = 0;
		while (i < words_nbr)
		{
			while (!is_delim(*s))
				s++;
			word_len = get_word_len(s);
			result[i] = ft_strsub(s, 0, word_len);
			s += word_len;
			i++;
		}
		result[i] = NULL;
	}
	return (result);
}
