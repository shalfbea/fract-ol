/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:36 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/27 19:49:31 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(int mode)
{
	if (mode == 0)
		printf("Error! No agruments at all.\n");
	else if (mode == 1)
		printf("Error! That's graph not available.\n");
	printf("Usage: ./fractol \"graph\" etc\n"); //fix message
	printf("Available graphs: Mandelbrot, Julia\n"); //to add fracs
	exit(0);
}

static void	input_fractal(char **argv, int *i, t_mlx *mlx, int argc)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mlx->frac_type = 1;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		mlx->frac_type = 2;
	else if (ft_strncmp(argv[1], "BurningShip", 11) == 0)
		mlx->frac_type = 3;
	else if (ft_strncmp(argv[1], "Tricorn", 11) == 0)
		mlx->frac_type = 4;
	//
	//
	else
	{
		error_msg(1);
		exit(0);
	}
	if (mlx->frac_type == 2 && argc > 3)
	{
		if (ft_strncmp(argv[*i], "default", 7) == 0)
			(*i)++;
		else
		{
			mlx->julia_const.real = simple_atof(argv[(*i)++]);
			mlx->julia_const.img = simple_atof(argv[(*i)++]);
		}
	}
}

static void	input_colors(char **argv, int *i, t_mlx *mlx, int argc)
{
	if (argc > (*i))
	{
		if (ft_strncmp(argv[*i], "default", 7) == 0)
		{
			set_default_colors(mlx);
			(*i)++;
		}
		else if (argc > *i)
		{
			mlx->color_r = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
			mlx->color_g = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
			mlx->color_b = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
		}
	}
}

void	input_handler(int argc, char **argv, t_mlx *mlx)
{
	int	i;

	if (argc < 2)
		error_msg(0);
	i = 2;
	input_fractal(argv, &i, mlx, argc);
	input_colors(argv, &i, mlx, argc);
	if (argc > i)
	{
		if (ft_strncmp(argv[i], "default", 7) == 0)
			++i;
		else
			mlx->max_iter = abs(ft_atoi(argv[i++])) % 500;
	}
}
