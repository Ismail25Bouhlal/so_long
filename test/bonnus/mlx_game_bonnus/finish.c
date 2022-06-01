/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:31:58 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 13:24:10 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	ft_sort(t_game *g)
{
	write (1, "out !\n", 6);
	ft_free(g);
	exit(0);
}

void	ft_free(t_game *g)
{
	int	i;

	i = 0;
	mlx_destroy_image(g->mlx, g->back);
	mlx_destroy_image(g->mlx, g->wall);
	mlx_destroy_image(g->mlx, g->play);
	mlx_destroy_image(g->mlx, g->call);
	mlx_destroy_image(g->mlx, g->exit);
	mlx_destroy_image(g->mlx, g->enemie);
	while (g->map[i])
	{
		free (g->map[i]);
		i++;
	}
	free (g->map);
}

void	ft_you_win(t_game *g)
{
	write(1, "you win!\n", 9);
	ft_free (g);
	exit (0);
}

void	ft_left(t_game *g)
{
	write(1, "you left!\n", 10);
	ft_free (g);
	exit (0);
}

void	ft_lose(t_game *g)
{
	write(1, "you lose!\n", 10);
	ft_free (g);
	exit (0);
}
