/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:21:29 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/06/01 12:38:12 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	m;

	if (ac != 2)
	{
		write(1, "Error\n Arguments incorrect !!", 30);
		return (1);
	}
	check_name (av[1]);
	m.fd = open(av[1], O_RDONLY);
	if (m.fd == -1)
	{
		write (1, "Error\nthis file does not exist :(", 34);
		return (close(m.fd), 1);
	}
	m.map = map (av);
	if (mapcheck (&m))
	{
		mlx_st (&m);
	}
	return (0);
}
