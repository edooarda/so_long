/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edooarda <edooarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:23:27 by edribeir          #+#    #+#             */
/*   Updated: 2025/01/29 20:13:14 by edooarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	ft_putendl_fd("ERROR", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

static void	checker_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".ber", 4))
		error_message("Please, use a .ber file for the Map");
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_message("Insert ONE FILE! Just ONE MAP!");
	checker_file_extension(argv[1]);
	game = turn_file_into_data(argv[1]);
	game.mlx = mlx_init((game.width * PIXELS),
			(game.height * PIXELS), "so_long", false);
	ft_putendl_fd("\nLet's Play! Ms. MOO is hungry 🍄!", 1);
	if (!game.mlx)
		error_message("MLX problem");
	game.textures = initialize_image_struct(&game);
	add_floor_window(&game);
	add_texture_window(&game);
	mlx_key_hook(game.mlx, ft_hook_moves, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map, game.height);
	return (free(game.textures), (EXIT_SUCCESS));
}
