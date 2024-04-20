/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:19 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:20 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = 0;
	return (res);
}
