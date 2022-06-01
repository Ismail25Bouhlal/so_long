/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:24:51 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 17:31:13 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonnus.h"

int	is_rectangular(t_map *m)
{
	t_map	s;

	s.len = ft_strlen (m->map[0]);
	s.i = 0;
	while (m->map[s.i])
	{
		if (s.len != ft_strlen (m->map[s.i]))
		{
			write (1, "Error\nnot rectangular!\n", 24);
			return (1);
		}
		s.i++;
	}
	return (0);
}

void	clacul(t_map *m, char **map)
{
	if (map[m->i][m->j] == 'C')
		m->c++;
	else if (map[m->i][m->j] == 'P')
		m->p++;
	else if (map[m->i][m->j] == 'E')
		m->e++;
	else if (map[m->i][m->j] == 'N')
		m->n++;
}

int	caracteres(char **map)
{
	t_map	m;

	m.i = 0;
	m.c = 0;
	m.p = 0;
	m.n = 0;
	m.e = 0;
	while (map[m.i])
	{
		m.j = 0;
		while (map[m.i][m.j])
		{
			clacul (&m, map);
			m.j++;
		}
		m.i++;
	}
	if (m.e == 1 && m.c > 0 && m.p == 1 && m.n > 0)
		return (0);
	write(1, "Error\ncarracter non valide !!", 30);
	return (1);
}

int	invalid_characters(t_map *m)
{
	m->i = 0;
	while (m->map[m->i])
	{
		m->j = 0;
		while (m->map[m->i][m->j])
		{
			if (m->map[m->i][m->j] != '1' && m->map[m->i][m->j] != '0'
				&& m->map[m->i][m->j] != 'P' && m->map[m->i][m->j] != 'C'
				&& m->map [m->i][m->j] != 'E' && m->map[m->i][m->j] != 'N')
			{
				write (1, "Eroor\nInvalid Characters", 25);
				return (1);
			}
			m->j++;
		}
		m->i++;
	}
	return (0);
}

int	mapcheck(t_map *m, char **ma)
{
	if (!is_rectangular (m) && !caracteres (ma)
		&& !invalid_characters (m) && !check_all_walls (m))
		return (1);
	return (0);
}
