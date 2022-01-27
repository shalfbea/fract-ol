/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:11:23 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/27 21:16:08 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# ifndef WINDOW_H
#  define WINDOW_H 400
# endif
# ifndef WINDOW_W
#  define WINDOW_W 400
# endif
# ifndef INIT_MAX_ITER
#  define INIT_MAX_ITER 100
# endif
# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 3
# endif
# ifndef MOVING_FACTOR
#  define MOVING_FACTOR 200
# endif

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define R_KEY 15
# define SPACE 49
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define WHEEL_DOWN 4
# define WHEEL_UP 5

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				max_iter;
	char			frac_type;
	double			center_x;
	double			center_y;
	double			scale;
	int				color_r;
	int				color_g;
	int				color_b;
	t_complex		julia_const;
}		t_mlx;

//To delete
int			ft_printf(const char *str, ...);
//fractals.c
int			mandelbrot(t_complex	z, t_mlx mlx);
int			julia(t_complex	z, t_mlx mlx);
int			burning_ship(t_complex	z, t_mlx mlx);
int			tricorn(t_complex	z, t_mlx mlx);

//render.c
int			colorizer(t_complex z, int n, t_mlx mlx);
void		draw_fractal(t_mlx mlx);
//controls.c
int			key_controls(int key, t_mlx *mlx);
int			mouse_controls(int button, int x, int y, t_mlx *mlx);
//main.c
int			mlx_close(t_mlx *mlx);
int			rerender(t_mlx *mlx);
int			init_params(t_mlx *mlx);
void		set_default_colors(t_mlx *mlx);
//inputs.c
void		input_handler(int argc, char **argv, t_mlx *mlx);
//ft_strings.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
double		simple_atof(const char *str);
#endif
