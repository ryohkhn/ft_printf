/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:37 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:38 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*save;

	save = 0;
	i = -1;
	while (s[++i])
	{
		if ((char)s[i] == (char)c)
			save = (char *)(s + i);
	}
	if (c == '\0')
	{
		return ((char *)(s + i));
	}
	return (save);
}
