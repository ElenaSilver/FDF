/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 23:32:15 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 02:53:52 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static size_t	count_file_lines(int fd)
{
	char	*line;
	size_t	n_lines;
	int		i;

	n_lines = 0;
	i = 0;
	if (fd > 0)
	{
		while ((ft_get_next_line(fd, &line)) == 1)
			n_lines++;
	}
	return (n_lines);
}

static int		check_error(int fd, const char *file)
{
	size_t	n_lines;
	int		**map;
	char	test[6];

	n_lines = count_file_lines(fd);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if ((read(fd, test, 1)) <= 0)
		return (0);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(map = fill_int_map(fd, n_lines)))
		return (0);
	close(fd);
	fdf_init(map, n_lines);
	return (1);
}

int				main(int ac, const char **av)
{
	int		fd;

	if (ac != 2)
		ft_putendl("usage: ./fdf <test_file>");
	else
	{
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		if (fd > 0)
		{
			if (!check_error(fd, av[1]))
				ft_putendl("File error");
		}
		else
			ft_putendl("File is invalid");
	}
	return (0);
}
