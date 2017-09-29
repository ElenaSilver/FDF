/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 01:47:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 00:31:16 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		*fill_int_map_lines(char *line)
{
	char	**tab;
	int		*map_line;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[len])
		len++;
	if (!(map_line = (int*)malloc(sizeof(int) * len + 1)))
		return (0);
	while (*tab)
	{
		map_line[i] = ft_atoi(*tab);
		i++;
		tab++;
	}
	map_line[i] = TAB_STOP;
	return (map_line);
}

static int		*fill_last_line(size_t x_max)
{
	int		*map_line;
	size_t	i;

	i = 0;
	if (!(map_line = (int*)malloc(sizeof(int) * x_max)))
		return (0);
	while (i < x_max)
	{
		map_line[i] = TAB_STOP;
		i++;
	}
	map_line[i] = TAB_STOP;
	return (map_line);
}

int				**fill_int_map(int fd, size_t n_lines)
{
	int		**map;
	char	*line;
	size_t	i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * n_lines + 1)))
		return (0);
	while ((ft_get_next_line(fd, &line)) == 1)
	{
		map[i] = fill_int_map_lines(line);
		i++;
	}
	map[i] = fill_last_line(x_len(map, n_lines));
	if (x_len(map, n_lines) > 0)
		return (map);
	else
		return (0);
}
