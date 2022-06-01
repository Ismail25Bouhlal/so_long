/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:41:26 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 13:22:01 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

void	up_en(t_game *g)
{
	if (g->map[g->a - 1][g->b] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a - 1][g->b] = 'N';
		g->enemie = mlx_xpm_file_to_image(g->mlx, \
			"im/enemy_up.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a - 1][g->b] == 'P')
		ft_lose (g);
}

void	down_en(t_game *g)
{
	if (g->map[g->a + 1][g->b] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a + 1][g->b] = 'N';
		g->enemie = mlx_xpm_file_to_image(g->mlx, \
			"im/enemy_down.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a + 1][g->b] == 'P')
		ft_lose (g);
}

void	left_en(t_game *g)
{
	if (g->map[g->a][g->b - 1] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a][g->b - 1] = 'N';
		g->enemie = mlx_xpm_file_to_image(g->mlx, \
			"im/enemy_left.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a][g->b - 1] == 'P')
		ft_lose (g);
}

void	right_en(t_game *g)
{
	if (g->map[g->a][g->b + 1] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a][g->b + 1] = 'N';
		g->enemie = mlx_xpm_file_to_image(g->mlx, \
			"im/enemy_right.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a][g->b + 1] == '0')
		ft_lose (g);
}
