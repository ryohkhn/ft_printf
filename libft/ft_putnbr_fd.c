/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:01 by lucarodr          #+#    #+#             */
/*   Updated: 2024/02/15 15:15:10 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_bis(long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
	else
	{
		ft_putnbr_fd_bis(nbr / 10, fd);
		ft_putnbr_fd_bis(nbr % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	ft_putnbr_fd_bis(nbr, fd);
}
