/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:57:55 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 14:16:11 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static size_t	tot_dig(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	sl;
	long	d;
	char	*s;

	sl = tot_dig(n);
	d = n;
	s = malloc(sl + 1);
	if (!s)
		return (NULL);
	while (d < 0)
	{
		s[0] = '-';
		d = d * -1;
	}
	if (d == 0)
		s[0] = '0';
	s[sl--] = '\0';
	while (d != 0)
	{
		s[sl] = d % 10 + '0';
		sl--;
		d = d / 10;
	}
	return (s);
}
