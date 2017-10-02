/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 01:47:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/02 16:12:03 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		put_pixel_to_image(int x, int y, t_fdf *e, int color)
{
	if (!(x > WIDTH - 1 || x < 0 || y > HEIGHT - 1 || y < 0) && color == 1)
	{
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = 204;
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = 0;
		e->data[(x * 4) + (y * WIDTH * 4)] = 0;
	}
	else if (!(x > WIDTH - 1 || x < 0 || y > HEIGHT - 1 || y < 0) && color == 2)
	{
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = 255;
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = 255;
		e->data[(x * 4) + (y * WIDTH * 4)] = 51;
	}
	else if (!(x > WIDTH - 1 || x < 0 || y > HEIGHT - 1 || y < 0) && color == 3)
	{
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = 153;
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = 51;
		e->data[(x * 4) + (y * WIDTH * 4)] = 255;
	}
	else if (!(x > WIDTH - 1 || x < 0 || y > HEIGHT - 1 || y < 0) && color == 4)
	{
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = 0;
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = 255;
		e->data[(x * 4) + (y * WIDTH * 4)] = 0;
	}
}

int			get_color(t_fdf *e, int x, int y)
{
	if (e->map[y][x] <= 0)
		return (1);
	else if (e->map[y][x] > 0 && e->map[y][x] <= 50)
		return (2);
	else if (e->map[y][x] >= 51 && e->map[y][x] <= 151)
		return (3);
	else
		return (4);
}

size_t		x_len(int **map, size_t y_max)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i][j] != TAB_STOP)
		j++;
	len = j;
	j = 0;
	while (i < y_max - 1)
	{
		while (map[i][j] != TAB_STOP)
			j++;
		if (j != len)
			return (0);
		j = 0;
		i++;
	}
	return (len);
}
