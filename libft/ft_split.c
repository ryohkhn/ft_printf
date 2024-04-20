/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:15 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:17 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	get_nb_words(char const *s, char c)
{
	int	i;
	int	acc;

	i = 0;
	acc = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			acc++;
		if (s[i++] == c && s[i] != c && s[i] != 0)
			acc++;
	}
	return (acc);
}

static char	**stralloc(int size)
{
	char	**res;

	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (0);
	res[size] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_len;
	char	**res;

	if (!s)
		return (NULL);
	res = stralloc(get_nb_words(s, c));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (*s && *s != c && ++word_len)
				s++;
			res[i++] = ft_substr(s - word_len, 0, word_len);
		}
		else
			s++;
	}
	return (res);
}
