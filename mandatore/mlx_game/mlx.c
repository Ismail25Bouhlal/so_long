/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:50:02 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/06/01 12:15:04 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	mlx_print_images(t_game *g)
{
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map [g->i][g->j] == '1')
				mlx_put_image_to_window (g->mlx, g->windows, \
					g->wall, g->j * g->width, g->i * g->height);
			else if (g->map [g->i][g->j] == '0')
				mlx_put_image_to_window (g->mlx, g->windows, \
					g->back, g->j * g->width, g->i * g->height);
			else if (g->map [g->i][g->j] == 'P')
				mlx_put_image_to_window (g->mlx, g->windows, \
					g->play, g->j * g->width, g->i * g->height);
			else if (g->map [g->i][g->j] == 'C')
				mlx_put_image_to_window (g->mlx, g->windows, \
					g->call, g->j * g->width, g->i * g->height);
			else if (g->map [g->i][g->j] == 'E')
				mlx_put_image_to_window (g->mlx, g->windows, \
					g->exit, g->j * g->width, g->i * g->height);
			g->j++;
		}
		g->i++;
	}
}

void	mlx_st(t_map *m)
{
	t_game	g;

	g.len = (int)ft_strlen(m->map[0]);
	g.mlx = mlx_init();
	g.windows = mlx_new_window(g.mlx, g.len * 50,
			count_line(m->map) * 50, "so_long");
	g.wall = mlx_xpm_file_to_image(g.mlx, "im/wall.xpm", &g.width, &g.height);
	g.play = mlx_xpm_file_to_image(g.mlx, "im/playerS.xpm",
			&g.width, &g.height);
	g.call = mlx_xpm_file_to_image(g.mlx, "im/coin0.xpm", &g.width, &g.height);
	g.back = mlx_xpm_file_to_image(g.mlx, "im/back.xpm", &g.width, &g.height);
	g.exit = mlx_xpm_file_to_image(g.mlx, "im/exit0.xpm", &g.width, &g.height);
	g.map = m->map;
	g.count = g.m.c;
	g.num = 0;
	g.m = *m;
	mlx_hook(g.windows, 2, 1L << 0, move_play, &g);
	mlx_hook(g.windows, 17, 0, ft_sort, &g);
	mlx_print_images(&g);
	mlx_loop (g.mlx);
}
