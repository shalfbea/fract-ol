/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:37:31 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/22 19:38:38 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	converter(double x, double y)
{
	t_complex res;
	res.real = (4*x) / WINDOW_W - 2;
	res.img  = (4*y) / WINDOW_H - 2;
	return (res);
}

int	 Mandelbrot_check(t_complex	z)
{
	int			iter;
	double		real_tmp;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;

	iter = 0;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (iter < MB_MAX_ITER))
	{
		real_tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + c.real;
		z.img = 2*z.img*real_tmp + c.img;
		iter++;
	}
	if (iter >= MB_MAX_ITER)
		return (0x000000);
	return (*(int *)(unsigned char [4]){iter % 8 * 16, iter % 4 * 32,iter % 2 * 64, 0});
}
void Mandelbrot(t_mlx mlx)
{
	int			x;
	int			y;
	t_complex 	z;

	x = 0;
	y = 0;
	while (++x < WINDOW_W)
	{
		//z.img = (4*((double) x)) / WINDOW_W - 2;
		z.img = ((x - WINDOW_W / 2) / mlx.scale + mlx.center_y);
		while (++y < WINDOW_H)
		{
			//z.real  = (4*((double) y)) / WINDOW_H - 2;
			z.real = ((y - WINDOW_H / 2) / mlx.scale + mlx.center_x);
			mlx.img.data[x*WINDOW_W + y] =  Mandelbrot_check(z);
		}
		y = 0;
	}
	return ;
}
