/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:09:57 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/08 17:47:22 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_words_number(char const *s, char delim)
{
	int result;
	int in_word;

	result = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!in_word && *s != delim)
		{
			in_word = 1;
			result++;
		}
		if (in_word && *s == delim)
		{
			in_word = 0;
		}
		s++;
	}
	return (result);
}

static int	get_word_len(char const *s, char delim)
{
	int i;

	i = 0;
	while (s[i] != delim && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words_nbr;
	char	**result;
	int		word_len;
	int		i;

	if (!s)
		return (NULL);
	words_nbr = get_words_number(s, c);
	result = (char**)malloc(sizeof(char*) * (words_nbr + 1));
	if (result != NULL)
	{
		i = 0;
		while (i < words_nbr)
		{
			while (*s == c)
				s++;
			word_len = get_word_len(s, c);
			result[i] = ft_strsub(s, 0, word_len);
			s += word_len;
			i++;
		}
		result[i] = NULL;
	}
	return (result);
}
