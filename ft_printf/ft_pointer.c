/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:20:40 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:42:30 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<unistd.h>

int	ft_pointer(unsigned long s)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (s >= 16)
	{
		count += ft_pointer(s / 16);
		count += ft_pointer(s % 16);
	}
	else if (s < 16)
	{
		count += write(1, &hex[s], 1);
	}
	return (count);
}
