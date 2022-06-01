/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:09:30 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:39:52 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_hex(nbr / 16);
		count += ft_hex(nbr % 16);
	}
	else if (nbr > 9)
	{
		count += ft_putchar(nbr + 55);
	}
	else
		count += ft_putchar(nbr + 48);
	return (count);
}
