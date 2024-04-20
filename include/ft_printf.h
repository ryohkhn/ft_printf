/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarodr <lucarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:05:38 by lucarodr          #+#    #+#             */
/*   Updated: 2024/04/15 11:05:40 by lucarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_print_char(const char c);
int				ft_print_string(const char *s);
unsigned int	getlength(unsigned int n);
char			*ft_utoa(unsigned int n);
int				ft_print_val_hex(unsigned int l, int type);
char			*ft_get_void_hex(void *p);
int				ft_print_void(void *p);
int				ft_conversion(va_list args, const char c);

#endif
