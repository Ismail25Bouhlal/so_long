/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:08:15 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:41:18 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexmin(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_hexmin(nbr / 16);
		count += ft_hexmin(nbr % 16);
	}
	else if (nbr > 9)
	{
		count += ft_putchar(nbr + 87);
	}
	else
		count += ft_putchar(nbr + 48);
	return (count);
}
