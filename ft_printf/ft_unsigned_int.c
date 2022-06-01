/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:50:12 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:50:23 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count(unsigned int nb)
{
	size_t	count;

	count = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_unsigned_int(unsigned int n)
{
	if (n > 9)
	{
		ft_unsigned_int(n / 10);
		ft_unsigned_int(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (count(n));
}
