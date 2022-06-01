/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_of_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:19:55 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 14:15:14 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	play_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map [i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	play_y(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	move_play(int key, void *pram)
{
	t_game	*l;

	l = (t_game *) pram;
	l->x = play_x(l->map);
	l->y = play_y(l->map);
	if (key == A)
		move_left(l);
	else if (key == S)
		move_down (l);
	else if (key == D)
		move_right (l);
	else if (key == W)
		move_up(l);
	else if (key == ESC)
		ft_sort (l);
	return (0);
}
