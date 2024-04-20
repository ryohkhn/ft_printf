/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:12 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 16:26:22 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (0);
		*(char *)res = '\0';
		return (res);
	}
	if (size >= SIZE_MAX || nmemb >= SIZE_MAX || (unsigned)nmemb != nmemb
		|| (unsigned)size != size)
		return (0);
	res = malloc(size * nmemb);
	if (!res)
		return (0);
	ft_bzero(res, size * nmemb);
	return (res);
}
