/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/06 17:01:03 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 520
#define HEIGHT 520

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t *display_image;
	int i;
	int j;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	display_image = mlx_new_image(mlx, 100, 100);
	i = 0;
	while(i < 100)
	{
		j = 0;
		while(j < 100)
		{
			mlx_put_pixel(display_image, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, display_image, 0, 0);
	mlx_loop(mlx);
}
