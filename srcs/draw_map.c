/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:15:44 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 02:54:09 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		draw_line(t_fdf *e, int x, int y)
{
	double	dx;
	double	dy;
	double	temp;
	double	x1;
	double	y1;

	x1 = e->x1;
	y1 = e->y1;
	dx = e->x2 - x1;
	dy = e->y2 - y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		put_pixel_to_image(x1, y1, e, get_color(e, x, y));
		x1 += dx;
		y1 += dy;
		temp--;
	}
	return (0);
}

static void		set_coordinates(t_fdf *e, int x, int y, int z)
{
	int		xt;
	int		yt;

	xt = x - e->x_max / 2;
	yt = y - e->y_max / 2;
	e->x1 = (xt - yt) * e->corr + 150;
	e->y1 = 0.5 * (xt + yt) * e->corr - 250;
	e->y1 -= e->map[y][x] * e->z_corr;
	if (z)
	{
		e->x2 = ((xt + 1) - yt) * e->corr + 150;
		e->y2 = 0.5 * ((xt + 1) + yt) * e->corr - 250;
		e->y2 -= e->map[y][x + 1] * e->z_corr;
	}
	else
	{
		e->x2 = (xt - (yt + 1)) * e->corr + 150;
		e->y2 = 0.5 * (xt + (yt + 1)) * e->corr - 250;
		e->y2 -= e->map[y + 1][x] * e->z_corr;
	}
	e->x1 += HEIGHT / 2;
	e->x2 += HEIGHT / 2;
	e->y1 += WIDTH / 2;
	e->y2 += WIDTH / 2;
}

static void		draw_map(t_fdf *e)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y++ != e->y_max && e->map[y][x] != TAB_STOP)
	{
		while (x++ != e->x_max && e->map[y][x] != TAB_STOP)
		{
			if (x + 1 < e->x_max && e->map[y][x] != TAB_STOP
					&& e->map[y][x + 1] != TAB_STOP)
			{
				set_coordinates(e, x, y, 1);
				draw_line(e, x, y);
			}
			if (y + 1 < e->y_max && e->map[y][x] != TAB_STOP
					&& e->map[y + 1][x] != TAB_STOP)
			{
				set_coordinates(e, x, y, 0);
				draw_line(e, x, y);
			}
		}
		x = 0;
	}
}

static int		image_init(t_fdf *e)
{
	int		bpp;
	int		size_line;
	int		endian;

	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->image, &bpp, &size_line, &endian);
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, e->left, e->up);
	put_string_screen(e);
	return (0);
}

int				fdf_init(int **map, size_t y_max)
{
	t_fdf	*e;

	if (!(e = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	e->map = map;
	e->y_max = y_max;
	e->x_max = x_len(map, y_max);
	e->corr = 1;
	e->left = 0;
	e->up = 0;
	e->z_corr = 0;
	if (!(e->mlx = mlx_init()))
		return (0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf: eserebry");
	mlx_key_hook(e->win, keycode, e);
	mlx_loop_hook(e->mlx, image_init, e);
	mlx_loop(e->mlx);
	return (0);
}
