/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:24 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:25 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dst;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (size + len_src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + len_src);
	i = len_dst;
	while (src[j] && j + 1 + len_dst < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_dst + len_src);
}
