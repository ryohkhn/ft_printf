/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:21:04 by lucarodr          #+#    #+#             */
/*   Updated: 2024/04/15 11:24:03 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_val_hex(unsigned int l, int type)
{
	char	*hex;
	int		count;

	count = 0;
	if (type == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (l >= 16)
	{
		count += ft_print_val_hex(l / 16, type);
	}
	ft_putchar_fd(hex[l % 16], STDOUT_FILENO);
	count++;
	return (count);
}

char	*ft_get_void_hex(void *p)
{
	int			size;
	uintptr_t	value;
	char		*hex;
	char		*buf;

	hex = "0123456789abcdef";
	value = (uintptr_t)p;
	size = sizeof(value) * 2;
	buf = malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (0);
	buf[size] = '\0';
	while (--size >= 0)
	{
		buf[size] = hex[value & 0xF];
		value >>= 4;
	}
	return (buf);
}

int	ft_print_void(void *p)
{
	char	*buf;
	int		offset;
	int		len;

	if (!p)
	{
		ft_print_string("(nil)");
		return (5);
	}
	buf = ft_get_void_hex(p);
	if (!buf)
		return (0);
	offset = -1;
	while (buf[++offset] == '0' && buf[offset] != '\0')
		;
	ft_print_string("0x");
	ft_print_string(buf + offset);
	len = ft_strlen(buf + offset);
	free(buf);
	return (len + 2);
}

int	ft_conversion(va_list args, const char c)
{
	int		count;
	char	*s;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_void(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
	{
		s = ft_itoa(va_arg(args, int));
		free((count = ft_print_string(s), s));
	}
	else if (c == 'u')
	{
		s = ft_utoa(va_arg(args, unsigned int));
		free((count = ft_print_string(s), s));
	}
	else if (c == 'x' || c == 'X')
		count = ft_print_val_hex(va_arg(args, unsigned int), c % 3);
	else if (c == '%')
		count = ft_print_char(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_count;
	va_list	args;

	i = 0;
	print_count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			print_count += ft_conversion(args, format[++i]);
		else
			print_count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_count);
}
