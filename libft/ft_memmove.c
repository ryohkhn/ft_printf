/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:14:48 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:49:49 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == src)
		return (dest);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
