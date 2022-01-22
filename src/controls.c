/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:39:34 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/22 16:36:25 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_controls(int key, void *mlx)
{
	(void) key;
	(void) mlx;
	ft_printf("Pressed key: %d\n", key);
	if (key == 53)
		mlx_close(mlx);
	return (1);
}

int mouse_controls(int button, int x, int y, void *mlx)
{
	(void) button;
	(void) x;
	(void) y;
	(void) mlx;
	ft_printf("Mouse: key(%d) at %d %d\n", button, x, y);
	return (1);
}
