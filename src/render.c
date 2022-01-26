/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:38:10 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/26 20:24:38 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colorizer(t_complex z, int n, t_mlx mlx)
{
	double			a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) mlx; //delete
	a = n + 2 - log(log(z.real * z.real + z.img * z.img)) / M_LN2;
	if (a < 0)
		a = 0;
	a = 8 * sqrt(a);
	r = (int)(floor(a * mlx.color_r)) % 256;
	g = (int)(floor(a * mlx.color_g)) % 256;
	b = (int)(floor(a * mlx.color_b)) % 256;
	return (*(int *)(unsigned char [4]){r, g, b, 0});
}

int	(*choose_fractal(t_mlx mlx))(t_complex z, t_mlx mlx)
{
	if (mlx.frac_type == 1)
		return (*mandelbrot);
	if (mlx.frac_type == 2)
		return (*julia);
	if (mlx.frac_type == 3)
		return (*burning_ship);
	exit(0);
}

void	draw_fractal(t_mlx mlx)
{
	int			x;
	int			y;
	t_complex	z;
	int			(*fractal)(t_complex z, t_mlx mlx);

	fractal = choose_fractal(mlx);
	x = 0;
	y = 0;
	while (++y < WINDOW_H)
	{
		z.img = ((y - WINDOW_H / 2) / mlx.scale + mlx.center_y);
		while (++x < WINDOW_W)
		{
			z.real = ((x - WINDOW_W / 2) / mlx.scale + mlx.center_x);
			mlx.img.data[y * WINDOW_W + x] =  fractal(z, mlx);
		}
		x = 0;
	}
}
