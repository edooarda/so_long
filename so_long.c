/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/11 15:02:38 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 820
#define HEIGHT 820

void	ft_keyhook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_image_t *display_image;
	mlx_image_t *display_image2;
	int x;
	int y;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	display_image = mlx_new_image(mlx, 300, 100);
	y = 0;
	while(y < 100)
	{
		x = 0;
		while(x < 300)
		{
			mlx_put_pixel(display_image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, display_image, 280, 300);


	display_image2 = mlx_new_image(mlx, 100, 300);
	y = 0;
	while(y < 300)
	{
		x = 0;
		while(x < 100)
		{
			mlx_put_pixel(display_image2, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, display_image2, 380, 210);
	mlx_key_hook(mlx, &ft_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
