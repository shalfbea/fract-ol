/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:37:31 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/22 15:21:09 by shalfbea         ###   ########.fr       */
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
	t_complex	prev;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;
	iter = 0;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (iter < MB_MAX_ITER))
	{
		prev.img = z.img;
		prev.real = z.real;
		z.real = pow(prev.real, 2) - pow(prev.img, 2) + c.real;
		z.img = 2*prev.img*prev.real + c.img;
		iter++;
	}
	if (iter >= MB_MAX_ITER)
		return (0x000000);
	return (*(int *)(unsigned char [4]){255-iter, 255 - iter,255, 0});
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
		z.img = (4*((double) x)) / WINDOW_W - 2;
		while(++y < WINDOW_H)
		{
			z.real  = (4*((double) y)) / WINDOW_H - 2;
			mlx.img.data[x*WINDOW_W + y] =  Mandelbrot_check(z);
		}
		y = 0;
	}
	return ;
}
