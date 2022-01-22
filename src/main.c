/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:52:47 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/22 19:36:58 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mlx_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	error_msg(int mode)
{
	if (mode == 0)
		printf("Error! No agruments at all.\n");
	else if (mode == 1)
		printf("Error! That's graph not available.\n");
	printf("Usage: ./fractol \"graph\" etc\n"); //fix message
	printf("Available graphs: Mandelbrot, Julia\n");
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
	mlx->frac_type = 1; //Заглушка
	return; 			//
	if(argc < 2)
		error_msg(0);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 )
		mlx->frac_type = 1;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		mlx->frac_type = 2;
	else
	{
		error_msg(1);
		mlx->frac_type = 0;
	}
}

int		init_params(t_mlx *mlx)
{
	mlx->scale = 200;
	mlx->center_x = 0.0;
	mlx->center_y = 1.0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	input_handler(argc, argv, &mlx);
	ft_printf("%d", mlx.frac_type); //удалить
	init_params(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_W, WINDOW_H, "fractol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WINDOW_W, WINDOW_H);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
	mlx_hook(mlx.win, 17, 0, mlx_close, &mlx);
	mlx_key_hook(mlx.win, key_controls, &mlx);
	mlx_mouse_hook(mlx.win, mouse_controls, &mlx);
	Mandelbrot(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx);
}
