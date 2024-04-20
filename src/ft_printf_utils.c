/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:14:06 by lucarodr          #+#    #+#             */
/*   Updated: 2024/04/15 11:24:38 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_char(const char c)
{
	int	w;

	w = write(1, &c, 1);
	return (w);
}

int	ft_print_string(const char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (ft_print_string("(null)"));
	while (s[++i])
		ft_print_char(s[i]);
	return (i);
}

unsigned int	getlength(unsigned int n)
{
	unsigned int	len;

	len = 2;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	char	*sp;

	str = malloc(getlength(n) * sizeof(char));
	if (!str)
		return (0);
	sp = str + getlength(n) - 1;
	*sp-- = '\0';
	while (sp - str >= 0)
	{
		*sp-- = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
