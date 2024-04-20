/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:41 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:43 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	new_len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		new_len = 0;
	else if (len < new_len)
		new_len = len;
	res = malloc(sizeof(char) * (new_len + 1));
	if (!res)
		return (0);
	while (i < new_len && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}
