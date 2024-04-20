/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:42 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:12:43 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	get_nb_digits(int n)
{
	int	i;

	i = (n == 0);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_itoa_bis(long n, char *res, int *pos)
{
	if (n < 0)
	{
		res[*pos] = '-';
		(*pos)++;
		n *= -1;
	}
	if (n < 10)
		res[(*pos)++] = n + '0';
	else
	{
		ft_itoa_bis(n / 10, res, pos);
		ft_itoa_bis(n % 10, res, pos);
	}
}

char	*ft_itoa(int n)
{
	int		mc_size;
	long	long_n;
	int		*pos;
	char	*res;

	pos = NULL;
	pos = malloc(sizeof(int));
	if (!pos)
		return (0);
	*pos = 0;
	long_n = n;
	mc_size = get_nb_digits(n) + (n < 0);
	res = malloc(sizeof(char) * (mc_size + 1));
	if (!res)
		return (0);
	ft_itoa_bis(long_n, res, pos);
	res[*pos] = 0;
	free(pos);
	return (res);
}
