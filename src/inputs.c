/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:36 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/26 19:19:53 by shalfbea         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] == s2[i]) && s1[i] && s2[i])
		++i;
	if (i == n)
		return ((int) 0);
	return ((unsigned char)s1[i] - s2[i]);
}

void	input_handler(int argc, char **argv, t_mlx *mlx)
{
	//mlx->frac_type = 1; //Заглушка
	//return; 			//
	if (argc < 2)
		error_msg(0);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mlx->frac_type = 1;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		mlx->frac_type = 2;
	else if (ft_strncmp(argv[1], "BurningShip", 11) == 0)
		mlx->frac_type = 3;
	else
	{
		error_msg(1);
		mlx->frac_type = 0;
	}
}
