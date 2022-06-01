/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:21:39 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 22:16:06 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg (ptr, char *)));
	else if ((c == 'i') || (c == 'd'))
		return (ft_putnbr(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_unsigned_int(va_arg(ptr, unsigned int)));
	else if (c == 'X')
		return (ft_hex(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_hexmin(va_arg(ptr, unsigned int)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_pointer(va_arg(ptr, unsigned long)));
	}
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
