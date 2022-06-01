/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:58:16 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:44:04 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			len += ft_putchar(str[i]);
		}
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_put(ptr, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
