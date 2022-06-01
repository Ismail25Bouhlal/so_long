/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wals_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:23:00 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 12:29:08 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	horizontal(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	horizontal_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	left_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	right_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_all_walls(t_map *m)
{
	if (! horizontal(m->map) && ! horizontal_line(m->map)
		&& ! left_line(m->map) && ! right_line(m->map))
		return (0);
	write(1, "Error\nPlease Check Walls !!", 28);
	return (1);
}
