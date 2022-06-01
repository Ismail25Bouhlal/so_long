/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:57:06 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/06/01 16:28:31 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_line(char **av)
{
	t_map	s;

	s.i = 0;
	s.fd = open(av[1], O_RDONLY);
	while (1)
	{
		s.tmp = get_next_line (s.fd);
		if (!s.tmp)
			break ;
		free(s.tmp);
		s.i++;
	}
	return (close(s.fd), s.i);
}

void	empty_map(char str)
{
	(void)str;
	write (1, "your map is empty :) !", 23);
	exit(1);
}

char	**map(char **av)
{
	t_map	p;

	p.str = ft_count_line(av);
	p.map = (char **) malloc(sizeof (char *) * (p.str + 1));
	if (!p.map)
		return (NULL);
	p.fd = open(av[1], O_RDONLY);
	p.i = -1;
	while (++p.i < p.str)
		p.map[p.i] = get_next_line(p.fd);
	p.i = -1;
	while (++p.i < p.str - 1)
	{
		p.str2 = p.map[p.i];
		p.map[p.i] = ft_substr(p.str2, 0, ft_strlen(p.str2) - 1);
		free(p.str2);
	}
	if (p.str == 0)
		empty_map(p.str);
	else if (!p.map)
		return (NULL);
	(p.i)++;
	p.map[p.i] = NULL;
	return (close(p.fd), p.map);
}
