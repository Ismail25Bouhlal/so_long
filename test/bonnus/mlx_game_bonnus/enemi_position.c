/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemi_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:45:36 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 13:18:03 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	en_a(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	en_b(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	move_en(t_game *g)
{
	int	i;

	g->a = en_a(g->map);
	g->b = en_b(g->map);
	i = rand() % 20;
	if (i == 1)
		up_en(g);
	else if (i == 2)
		down_en(g);
	else if (i == 3)
		left_en(g);
	else if (i == 4)
		right_en(g);
	coin_animation(g);
	mlx_print(g);
	return (0);
}
