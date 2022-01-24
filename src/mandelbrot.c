/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:37:31 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/24 13:39:49 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_simple_axis(t_mlx mlx)
{
	int	x;

	x = -1;
	while (++x < WINDOW_W)
			mlx.img.data[x * WINDOW_W + WINDOW_H / 2] =  0xFFFFFF;
	x = -1;
	while (++x < WINDOW_H)
			mlx.img.data[(WINDOW_H / 2) * WINDOW_W + x] =  0xFFFFFF;
	return (0);
}

unsigned char	periodic_color (int x)
{
  if ( x < 128 )
    return 128+x;
  else if ( x < 384 )
    return 383-x;
  else
    return x-384;
}

int colorizer(t_complex z, int n)
{
	double			a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

    a = n+2 - log(log(z.real * z.real+z.img * z.img))/M_LN2;
    if ( a < 0 )
		a = 0;
    a = 8*sqrt(a);
	r = periodic_color ((int)(floor(a*2))%512);
    g = periodic_color ((int)(floor(a*3))%512);
	b = periodic_color ((int)(floor(a*5))%512);
	return (*(int *)(unsigned char [4])
	{r, g , b , 0});
}
int	mandelbrot_check(t_complex	z)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.img = z.img;
	c.real = z.real;
	iter = -1;
	while ((pow(z.real, 2) + pow(z.img, 2) < 4) && (++iter < MB_MAX_ITER))
	{
		tmp = z.real;
		z.real = pow(z.real, 2) - pow(z.img, 2) + c.real;
		z.img = 2 * z.img * tmp + c.img;
	}
	if (iter == 0)
		return (0x0000FF);
	if (iter >= MB_MAX_ITER)
		return (0x000000);
	tmp = iter/MB_MAX_ITER;
	return colorizer(z, iter);
	//return (*(int *)(unsigned char [4])
	//{tmp*255, tmp*255,0, 0});
	//{(int)(tmp*150 + (1-tmp)*115),(int)(tmp*150 + (1-tmp)*115),(int)(tmp*150 + (1-tmp)*115), 0});

}

void	mandelbrot(t_mlx mlx)
{
	int			x;
	int			y;
	t_complex	z;

	x = 0;
	y = 0;
	while (++y < WINDOW_H)
	{
		//z.img = (4*((double) x)) / WINDOW_W - 2;
		z.img = -((y - WINDOW_H / 2) / mlx.scale + mlx.center_y);
		while (++x < WINDOW_W)
		{
			//z.real  = (4*((double) y)) / WINDOW_H - 2;
			z.real = ((x - WINDOW_W / 2) / mlx.scale + mlx.center_x);
			mlx.img.data[y * WINDOW_W + x] =  mandelbrot_check(z);
		}
		x = 0;
	}
	return ;
}
