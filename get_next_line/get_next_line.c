/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:54:59 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/05/30 14:27:44 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

char	*ft_line_after(char *str)
{
	int		i;
	char	*rest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			rest = ft_substr(str, i, ft_strlen(&str[i]));
			free(str);
			return (rest);
		}
		i++;
	}
	free(str);
	return (NULL);
}

char	*line_before(char *save)
{
	int		i;
	char	*ret;

	if (!save[0])
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	else if (save[i] == '\0')
		return (save);
	ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (save[i] != '\n')
	{
		ret[i] = save[i];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	return (ret);
}

char	*read_get_next_line(int fd, char *buf, char *save)
{
	int		count;

	count = 1;
	while (count && !ft_strchr(save))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[count] = '\0';
		if (!save)
			save = ft_strdup("");
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*save;
	char			*line;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (NULL);
	}
	save = read_get_next_line(fd, buf, save);
	if (!save)
		return (NULL);
	line = line_before (save);
	if (line == save)
		save = NULL;
	save = ft_line_after(save);
	return (line);
}
