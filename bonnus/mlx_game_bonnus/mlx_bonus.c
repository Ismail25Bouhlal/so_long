/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:50:02 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 13:24:44 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

void	xpm_to_img(t_game *g)
{
	g->wall = mlx_xpm_file_to_image(g->mlx, \
		"im/wall.xpm", &g->width, &g->height);
	g->back = mlx_xpm_file_to_image(g->mlx, \
		"im/back.xpm", &g->width, &g->height);
	g->play = mlx_xpm_file_to_image(g->mlx, \
		"im/playerS.xpm", &g->width, &g->height);
	g->call = mlx_xpm_file_to_image(g->mlx, \
		"im/coin0.xpm", &g->width, &g->height);
	g->exit = mlx_xpm_file_to_image(g->mlx, \
		"im/exit0.xpm", &g->width, &g->height);
	g->enemie = mlx_xpm_file_to_image(g->mlx, \
		"im/enemy_down.xpm", &g->width, &g->height);
}

void	mlx_print_images(t_game *g)
{
	if (g->map[g->i][g->j] == '1')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->wall, g->j * g->width, g->i * g->height);
	else if (g->map[g->i][g->j] == '0')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->back, g->j * g->width, g->i * g->height);
	else if (g->map[g->i][g->j] == 'P')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->play, g->j * g->width, g->i * g->height);
	else if (g->map[g->i][g->j] == 'C')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->call, g->j * g->width, g->i * g->height);
	else if (g->map[g->i][g->j] == 'E')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->exit, g->j * g->width, g->i * g->height);
	else if (g->map[g->i][g->j] == 'N')
		mlx_put_image_to_window(g->mlx, g->windows, \
			g->enemie, g->j * g->width, g->i * g->height);
}

void	coin_animation(t_game *g)
{
	static int	i;

	if (i <= 10)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin0.xpm", &g->width, &g->height);
	else if (i <= 20)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin1.xpm", &g->width, &g->height);
	else if (i <= 30)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin2.xpm", &g->width, &g->height);
	else if (i <= 40)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin3.xpm", &g->width, &g->height);
	else if (i <= 50)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin4.xpm", &g->width, &g->height);
	else if (i <= 60)
		g->call = mlx_xpm_file_to_image(g->mlx, \
			"im/coin5.xpm", &g->width, &g->height);
	i++;
	if (i == 60)
		i = 0;
}

void	mlx_print(t_game *g)
{
	char	*s;

	s = ft_itoa(g->num);
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			mlx_print_images(g);
		g->j++;
		}
	g->i++;
	}	
	mlx_string_put(g->mlx, g->windows, 10, 10, 0x0042f5a7, "Moves");
	mlx_string_put(g->mlx, g->windows, 100, 10, 0x0042f5a7, s);
	free(s);
}

void	mlx_start(char **map)
{
	t_game	g;

	g.len = (int)ft_strlen(map[0]);
	g.mlx = mlx_init();
	g.windows = mlx_new_window(g.mlx, g.len * 50, lines(map) * 50, \
		"so_long_bonus");
	xpm_to_img(&g);
	g.map = map;
	g.num = 0;
	g.loop = 0;
	mlx_hook(g.windows, 2, 0, move_play, &g);
	mlx_loop_hook(g.mlx, move_en, &g);
	mlx_hook(g.windows, 17, 0, ft_sort, &g);
	mlx_print(&g);
	mlx_loop(g.mlx);
}
