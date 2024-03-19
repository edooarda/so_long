/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/19 17:14:24 by edribeir      ########   odam.nl         */
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
int32_t	main(int argc, char **argv)
{
	// mlx_t	*mlx;
	char	*map;
	// mlx_image_t *display_image;
	// mlx_image_t *display_image2;
	// mlx_texture_t *background_img;
	// mlx_image_t *background;
	// int x;
	// int y;
	if (argc != 2)
	{
		ft_printf("Error\nInsert ONE FILE! Just ONE MAP!\n");
		exit(EXIT_FAILURE);
	}
	// if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// display_image = mlx_new_image(mlx, 300, 100);
	// y = 0;
	// while(y < 100)
	// {
	// 	x = 0;
	// 	while(x < 300)
	// 	{
	// 		mlx_put_pixel(display_image, x, y, 0xFFFFFFFF);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_image_to_window(mlx, display_image, 280, 300);
	
	// display_image2 = mlx_new_image(mlx, 100, 300);
	// y = 0;
	// while(y < 300)
	// {
	// 	x = 0;
	// 	while(x < 100)
	// 	{
	// 		mlx_put_pixel(display_image2, x, y, 0xFFFFFF);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_image_to_window(mlx, display_image2, 380, 210);

	// background_img = mlx_load_png("./texture/rock.png");
	// background = mlx_texture_to_image(mlx, background_img);
	// mlx_image_to_window(mlx, background, WIDTH, HEIGHT);
	checker_file_extension(argv[1]);
	map = read_map(argv[1]);
	map_checkers(map);
	ft_printf("%s", map);
	// mlx_key_hook(mlx, &ft_keyhook, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
