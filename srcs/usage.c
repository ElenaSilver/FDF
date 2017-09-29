/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:38:44 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 02:51:59 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_string_screen(t_fdf *e)
{
	char *str1;
	char *str2;

	str1 = "Use arrows to move the map";
	str2 = "Use a/z to manage map height";
	mlx_string_put(e->mlx, e->win, 10, 10, 0x33cc33, "How to use:");
	mlx_string_put(e->mlx, e->win, 10, 40, 0xadebad, "+/- zoom in/zoom out");
	mlx_string_put(e->mlx, e->win, 10, 60, 0xadebad, str1);
	mlx_string_put(e->mlx, e->win, 10, 80, 0xadebad, str2);
	mlx_string_put(e->mlx, e->win, 10, 100, 0xadebad, "To exit: press ESC");
}

int		keycode(int keycode, t_fdf *e)
{
	if (keycode == 69 || keycode == 24)
	{
		e->corr = e->corr + 1;
		e->z_corr = e->z_corr + 0.1;
	}
	if (keycode == 78 || keycode == 27)
	{
		e->corr = e->corr - 1;
		e->z_corr = e->z_corr - 0.1;
	}
	if (keycode == 0)
		e->z_corr += 1;
	if (keycode == 6)
		e->z_corr -= 1;
	if (keycode == 126)
		e->up -= 5;
	if (keycode == 125)
		e->up += 5;
	if (keycode == 123)
		e->left -= 5;
	if (keycode == 124)
		e->left += 5;
	if (keycode == 53)
		exit(0);
	return (0);
}
