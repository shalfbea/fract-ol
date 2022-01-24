/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:39:34 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/24 12:01:51 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_controls(int key, t_mlx *mlx)
{
	(void) key;
	(void) mlx;
	ft_printf("Pressed key: %d\n", key);
	if (key == 53)
		mlx_close(mlx);
	else if (key == PLUS)
	{
		ft_printf("Pressed PLUS %d\n", key);
		mlx->scale *= SCALE_FACTOR;
		rerender(mlx);
	}
	else if (key == MINUS)
	{
		ft_printf("Pressed MINUS %d\n", key);
		mlx->scale /= SCALE_FACTOR;
		rerender(mlx);
	}

	return (1);
}

int	mouse_controls(int button, int x, int y, t_mlx *mlx)
{
	(void) button;
	(void) x;
	(void) y;
	(void) mlx;
	t_complex z;

	z.img = -((y - WINDOW_H / 2) / mlx->scale + mlx->center_y);
	z.real = ((x - WINDOW_W / 2) / mlx->scale + mlx->center_x);
	printf("Mouse: key(%d) at %d %d x=%f y=%f\n", button, x, y, z.real, z.img);
	if (button == MOUSE_LEFT || button == WHEEL_DOWN)
	{
		mlx->center_y = -((y - WINDOW_H / 2) / mlx->scale + mlx->center_y);
		mlx->center_x = ((x - WINDOW_W / 2) / mlx->scale + mlx->center_x);
		mlx->scale *= SCALE_FACTOR;
		rerender(mlx);
	}
	return (1);
}
