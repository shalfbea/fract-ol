/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:11:23 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/22 19:36:05 by shalfbea         ###   ########.fr       */
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
#  define WINDOW_H 1000
# endif
# ifndef WINDOW_W
#  define WINDOW_W 1000
# endif
# ifndef MB_MAX_ITER
#  define MB_MAX_ITER 100
# endif
# ifndef MOVE_SCALE
#  define MOVE_SCALE 3
# endif

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define WHEEL_UP 5
# define WHEEL_DOWN 4

# define COLOR_WHITE #FFFFFF
# define COLOR_BLACK	#000000
# define COLOR_RED		#FF0000
# define COLOR_GREEN	#00FF00
# define COLOR_BLUE		#0000FF

typedef struct	s_img
{
	void		*img_ptr;
	int			*data; //Here you got an int * even though mlx_get_data_addr returns
						//a char *, i'll talk more about this in the .c file.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

/*
**  Here is my main struct containing every variables needed by the MLX.
**  - mlx_ptr stores the return value of mlx_init
**  - win stores the return value of mlx_new_window
**  - img will store everything we need for the image part, the struct is described above.
*/
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		frac_type;
	double		center_x;
	double		center_y;
	double		scale;
}		t_mlx;

typedef struct	s_complex
{
	double	real;
	double	img;
}	t_complex;

//To delete
int		ft_printf(const char *str, ...);
//mandelbrot.c
void Mandelbrot(t_mlx mlx);
t_complex	converter(double x, double y);
//controls.c
int	key_controls(int key, void *mlx);
int mouse_controls(int button, int x, int y, void *mlx);
//main.c
int	mlx_close(t_mlx *mlx);
#endif
