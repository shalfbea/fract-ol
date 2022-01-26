/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:36 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/26 20:59:40 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(int mode)
{
	if (mode == 0)
		printf("Error! No agruments at all.\n");
	else if (mode == 1)
		printf("Error! That's graph not available.\n");
	printf("Usage: ./fractol \"graph\" etc\n"); //fix message
	printf("Available graphs: Mandelbrot, Julia\n"); //to add fracs
	exit(0);
}

void	choose_fractal(char *arg, t_mlx *mlx)
{
	if (ft_strncmp(arg, "Mandelbrot", 10) == 0)
		mlx->frac_type = 1;
	else if (ft_strncmp(arg, "Julia", 5) == 0)
		mlx->frac_type = 2;
	else if (ft_strncmp(arg, "BurningShip", 11) == 0)
		mlx->frac_type = 3;
	else
	{
		error_msg(1);
		mlx->frac_type = 0;
	}
}

void	input_handler(int argc, char **argv, t_mlx *mlx)
{
	int	i;

	if (argc < 2)
		error_msg(0);
	choose_fractal(argv[1], mlx);
	i = 2;
	if (mlx->frac_type == 2 && argc > 3)
	{
		// Считать значения для фрактала Жулиа + добавить default
	}
	if (argc > i)
	{
		if (ft_strncmp(argv[i], "default", 7) == 0)
			set_default_colors(mlx);
		mlx->frac_type = 2;
	}
	if (argc > i + 2)
	{

	}
}
