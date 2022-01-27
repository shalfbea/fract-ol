/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:37:31 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/27 18:32:23 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;
	iter = -1;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + c.real;
		z.img = 2 * z.img * tmp + c.img;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	tmp = iter / mlx.max_iter;
	return (colorizer(z, iter, mlx));
}

int	julia(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;

	iter = -1;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + mlx.julia_const.real;
		z.img = 2 * z.img * tmp + mlx.julia_const.img;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	tmp = iter / mlx.max_iter;
	return (colorizer(z, iter, mlx));
}

int	burning_ship(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;
	iter = -1;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + c.real;
		z.img = fabs(2 * z.img * tmp) + c.img;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	tmp = iter / mlx.max_iter;
	return (colorizer(z, iter, mlx));
}

int	tricorn(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;
	iter = -1;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + c.real;
		z.img = -2 * z.img * tmp + c.img;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	tmp = iter / mlx.max_iter;
	return (colorizer(z, iter, mlx));
}
