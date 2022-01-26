/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:52:47 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/26 21:00:18 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mlx_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void set_default_colors(t_mlx *mlx)
{
	//to_do
}

int	init_params(t_mlx *mlx)
{
	mlx->scale = 200;
	mlx->center_x = 0.0;
	mlx->center_y = 0.0;
	mlx->max_iter = INIT_MAX_ITER;
	mlx->julia_const.img = 0.756;
	mlx->julia_const.real = -0.1244;
	mlx->color_r = 5;
	mlx->color_g = 3;
	mlx->color_b = 2;
	//set_render_area(mlx, 0);
	return (0);
}

int	rerender(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WINDOW_W, WINDOW_H);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_l), &(mlx->img.endian));
	draw_fractal(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	input_handler(argc, argv, &mlx);
	ft_printf("%d", mlx.frac_type); //удалить
	init_params(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_W, WINDOW_H, "fractol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WINDOW_W, WINDOW_H);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
			&mlx.img.size_l, &mlx.img.endian);
	mlx_hook(mlx.win, 17, 0, mlx_close, &mlx);
	mlx_key_hook(mlx.win, key_controls, &mlx);
	mlx_mouse_hook(mlx.win, mouse_controls, &mlx);
	draw_fractal(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx);
}
