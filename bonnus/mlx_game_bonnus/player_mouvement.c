/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:42:37 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 13:33:56 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	coin_count(t_game *g)
{
	g->count = 0;
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map[g->i][g->j] == 'C')
				g->count++;
			g->j++;
		}
		g->i++;
	}
	return (g->count);
}

void	move_left(t_game *g)
{
	if (g->map [g->x][g->y - 1] != '1'
		&& g->map [g->x][g->y - 1] != 'E' && g->map [g->x][g->y - 1] != 'N')
	{
		if (g->map [g->x][g->y - 1] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y - 1] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerA.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x][g->y - 1] == 'E' && coin_count (g) == 0)
		ft_you_win (g);
	else if (g->map[g->x][g->y - 1] == 'N')
		ft_lose (g);
	if (coin_count (g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print(g);
}

void	move_right(t_game *g)
{
	if (g->map [g->x][g->y + 1] != '1'
		&& g->map [g->x][g->y + 1] != 'E' && g->map[g->x][g->y + 1] != 'N')
	{
		if (g->map [g->x][g->y + 1] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y + 1] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerD.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x][g->y + 1] == 'E' && coin_count (g) == 0)
		ft_you_win (g);
	else if (g->map[g->x][g->y + 1] == 'N')
		ft_lose (g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print (g);
}

void	move_up(t_game *g)
{
	if (g->map[g->x - 1][g->y] != '1'
		&& g->map [g->x - 1][g->y] != 'E' && g->map[g->x - 1][g->y] != 'N')
	{
		if (g->map [g->x - 1][g->y] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x - 1][g->y] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerW.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x - 1][g->y] == 'E' && coin_count (g) == 0)
		ft_you_win (g);
	else if (g->map[g->x - 1][g->y] == 'N')
		ft_lose (g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print (g);
}

void	move_down(t_game *g)
{
	if (g->map[g->x + 1][g->y] != '1'
		&& g->map[g->x + 1][g->y] != 'E' && g->map[g->x + 1][g->y] != 'N')
	{
		if (g->map [g->x + 1][g->y] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x + 1][g->y] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerS.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x + 1][g->y] == 'E' && coin_count(g) == 0)
		ft_you_win (g);
	else if (g->map[g->x + 1][g->y] == 'N')
		ft_lose (g);
	if (coin_count (g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print (g);
}
