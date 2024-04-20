/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:17 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:59:51 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if ((char) s[i] == (char) c)
			return ((char *)(s + i));
	}
	if (c == '\0')
	{
		return ((char *)(s + i));
	}
	return (0);
}
