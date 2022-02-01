/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:36 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/01 11:07:56 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(int mode)
{
	if (mode == 0)
		printf("Error! No agruments at all.\n");
	else if (mode == 1)
		printf("Error! That's graph not available.\n");
	printf("General usage: ./fractol \"graph\"\n\
Available graphs: Mandelbrot, Julia, BurningShip, Tricorn\n\
You can also set params for Julia set, adding them after the name\n\
Example: ./fractol Julia 0.756 -0.1244 (or use \"default\" instead)\n\
Advanced usage: ./fractol \"graph\" [x y]/default [r g b]/default\n");
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
			(*i)++;
		else if (argc > *i + 2)
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
	printf("Control keys:\nArrows for moving\nMouse wheel or clicks \
for zooming in and out\nR key for reset\nN key to circle throw graphs\n\
Space for color shifting\nPlus and Minus keys for zooming with \
static center\nL key for making image prettier\n\
Also K key for making it worse if possible\nEnjoy the complexum world!\n");
}
