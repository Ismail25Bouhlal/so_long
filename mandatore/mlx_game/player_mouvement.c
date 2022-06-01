/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:42:37 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/06/01 12:09:58 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_game *g)
{
	if (g->map [g->x][g->y - 1] != '1' && g->map [g->x][g->y - 1] != 'E')
	{
		if (g->map [g->x][g->y - 1] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y - 1] = 'P';
		g->num++;
		ft_printf("%d\n", g->num);
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerA.xpm", &g->width, &g->height);
	}
	else if (g->map [g->x][g->y - 1] == 'E' && g->m.c == 0)
		ft_you_win(g);
	if (g->m.c == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print_images(g);
}

void	move_right(t_game *g)
{
	if ((g-> map [g->x][g->y + 1] == '0' \
		&& g->map [g->x][g->y + 1] != 'E') || g->map [g->x][g->y + 1] == 'C')
	{
		if (g->map [g->x][g->y + 1] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y + 1] = 'P';
		g->num++;
		ft_printf("%d\n", g->num);
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerD.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x][g->y + 1] == 'E' && g->m.c == 0)
		ft_you_win(g);
	if (g->m.c == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print_images (g);
}

void	move_up(t_game *g)
{
	if (g->map[g->x - 1][g->y] != '1' && g->map [g->x - 1][g->y] != 'E')
	{
		if (g->map [g->x - 1][g->y] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x - 1][g->y] = 'P';
		g->num++;
		ft_printf("%d\n", g->num);
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerW.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x - 1][g->y] == 'E' && g->m.c == 0)
		ft_you_win(g);
	if (g->m.c == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print_images(g);
}

void	move_down(t_game *g)
{
	if (g->map[g->x + 1][g->y] != '1' && g->map[g->x + 1][g->y] != 'E')
	{
		if (g->map [g->x + 1][g->y] == 'C')
			g->m.c--;
		g->map[g->x][g->y] = '0';
		g->map[g->x + 1][g->y] = 'P';
		g->num++;
		ft_printf("%d\n", g->num);
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"im/playerS.xpm", &g->width, &g->height);
	}
	else if (g->map [g->x + 1][g->y] == 'E' && g->m.c == 0)
		ft_you_win(g);
	if (g->m.c == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"im/exit1.xpm", &g->width, &g->height);
	mlx_print_images(g);
}
