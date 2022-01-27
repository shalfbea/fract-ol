/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:39:34 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/27 21:14:32 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	moving(int key, t_mlx *mlx)
{
	if (key == UP)
		mlx->center_y -= (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == DOWN)
		mlx->center_y += (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == LEFT)
		mlx->center_x -= (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == RIGHT)
		mlx->center_x += (double)(MOVING_FACTOR) / (mlx->scale);
}

static int	debug_info(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 50, 50, 0xFF0000, "kek");
	return (0);
}

int	key_controls(int key, t_mlx *mlx)
{
	ft_printf("Pressed key: %d\n", key);
	if (key == 53)
		mlx_close(mlx);
	else if (key == PLUS)
		mlx->scale *= SCALE_FACTOR;
	else if (key == MINUS)
		mlx->scale /= SCALE_FACTOR;
	else if (key == R_KEY)
		init_params(mlx);
	else if (key > 122 && key < 127)
		moving(key, mlx);
	else
	{
		if (key == SPACE)
			debug_info(mlx);
		return (0);
	}
	rerender(mlx);
	return (1);
}

int	mouse_controls(int button, int x, int y, t_mlx *mlx)
{
	mlx->center_y = ((y - WINDOW_H / 2) / mlx->scale + mlx->center_y);
	mlx->center_x = ((x - WINDOW_W / 2) / mlx->scale + mlx->center_x);
	if (button == MOUSE_LEFT || button == WHEEL_DOWN)
	{
		mlx->scale *= SCALE_FACTOR;
		if (mlx->max_iter < 200)
			mlx->max_iter = INIT_MAX_ITER;
		mlx->max_iter += 5;
	}
	if (button == MOUSE_RIGHT || button == WHEEL_UP)
	{
		mlx->scale /= SCALE_FACTOR;
		if (mlx->max_iter > 200)
			mlx->max_iter = INIT_MAX_ITER;
		mlx->max_iter -= 5;
	}
	rerender(mlx);
	return (1);
}
