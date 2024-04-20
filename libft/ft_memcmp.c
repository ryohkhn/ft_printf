/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:14:42 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:14:43 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (cp1[i] != cp2[i])
			return (cp1[i] - cp2[i]);
	}
	return (0);
}
