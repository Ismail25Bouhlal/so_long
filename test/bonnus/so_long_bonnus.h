/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonnus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:42:55 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/06/01 16:31:14 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONNUS_H
# define SO_LONG_BONNUS_H

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**arr;
	int		number_line_x;
	int		number_line_y;
	char	*tmp;
	int		fd;
	int		i;
	int		num;
	int		len;
	int		c;
	int		p;
	int		e;
	int		n;
	int		j;
	int		en;
	char	str;
	char	*str2;
	char	**map;
}	t_map;

typedef struct game
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;
	int		len;
	int		s;
	int		num;
	int		a;
	int		b;
	int		width;
	int		height;
	int		count;
	int		loop;
	void	*mlx;
	void	*windows;
	void	*keys;
	void	*wall;
	void	*back;
	void	*call;
	void	*play;
	void	*enemie;
	void	*exit;
	t_map	m;
}	t_game;

int		ft_count_line(char **av);
char	**map(char **av);
int		is_rectangular(t_map *map);
int		caracteres(char **map);
int		invalid_characters(t_map *map);
int		mapcheck(t_map *map, char **ma);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_name(char *file);
int		num_of_line(char **av);
char	**map(char **av);
int		horizontal(char **map);
int		horizontal_line(char **map);
int		left_line(char **map);
int		right_line(char **map);
int		check_all_walls(t_map *map);
int		ft_sort(t_game *g);
void	ft_free(t_game *g);
void	ft_you_win(t_game *g);
void	ft_left(t_game *g);
void	ft_lose(t_game *g);
int		count_line(char **map);
void	mlx_print_images(t_game *g);
void	coin_animation(t_game *g);
void	mlx_print(t_game *g);
void	xpm_to_img(t_game *g);
void	mlx_st(t_map *m);
void	mlx_start(char **map);
int		count_coin(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	empty_map(char str);
int		play_x(char **map);
int		play_y(char **map);
int		move_play(int key, void *pram);
int		en_a(char **map);
int		en_b(char **map);
int		move_en(t_game *g);
char	*ft_itoa(int n);
int		lines(char **map);
void	up_en(t_game *g);
void	down_en(t_game *g);
void	left_en(t_game *g);
void	right_en(t_game *g);
int		coin_count(t_game *g);

#endif