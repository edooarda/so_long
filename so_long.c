/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/28 16:09:09 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	ft_printf("ERROR\n");
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	checker_file_extension(char *file)
{
	int	len;
	
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".ber", 4))
		error_message("Please, use a .ber file for the Map");
}

void	ft_keyhook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}
int32_t	main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		error_message("Insert ONE FILE! Just ONE MAP!");
	checker_file_extension(argv[1]);
	game = turn_file_into_data(argv[1]); 
	if (!(game->mlx = mlx_init((game->width * PIXELS), (game->height * PIXELS), "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	game->textures = initialize_image_struct(game);
	add_texture_window(game, game->map);
	mlx_key_hook(game->mlx, &ft_keyhook, game->mlx);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}


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