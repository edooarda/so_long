/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:31:13 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/28 16:18:14 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*add_wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*rock;

	rock = mlx_load_png("texture/rock.png");
	if (rock == NULL)
		error_message("Problem with loading Image");
	image->rock = mlx_texture_to_image(mlx, rock);
	if (image->rock == NULL)
		error_message("Problem add texture image");
	// mlx_delete_texture(rock);
	return (image);
}

void	add_texture_window(t_game *game, char **map)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (map[line][col] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->textures->rock,
						col * PIXELS, line * PIXELS) < 0)
					error_message("Failed to put image to window");
			}
			col++;
		}
		line++;
	}
}

