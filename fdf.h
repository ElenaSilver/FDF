/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:57:59 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 01:27:38 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800
# define TAB_STOP 20000

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*data;
	int		**map;
	size_t	x_max;
	size_t	y_max;
	int		corr;
	float	z_corr;
	int		left;
	int		up;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}				t_fdf;

int				fdf_init(int **map, size_t n_lines);
int				**fill_int_map(int fd, size_t n_lines);
int				get_color(t_fdf *e, int x, int y);
int				keycode(int keycode, t_fdf *e);
void			put_string_screen(t_fdf *e);
void			put_pixel_to_image(int x, int y, t_fdf *env, int color);
size_t			x_len(int **map, size_t y_max);

#endif
