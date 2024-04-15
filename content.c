/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   content.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 12:04:30 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/15 18:01:37 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectable_counter(char **map)
{
	int	collectable;
	int	line;
	int	col;

	collectable = 0;
	line = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == 'C')
				collectable++;
			col++;
		}
		line++;
	}
	return (collectable);
}

void	element_position(char **map, t_game *game)
{
	int		col;
	int		line;

	line = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == 'P')
			{
				game->player_position_x = col;
				game->player_position_y = line;
			}
			if (map[line][col] == 'E')
			{
				game->exit_position_x = col;
				game->exit_position_y = line;
			}
			col++;
		}
		line++;
	}
	return ;
}

t_game	*initialize_game_struct(char **map, int height)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		error_message("Memory Allocation Failed");
	game->map = map;
	game->moves = 0;
	game->collectable = collectable_counter(map);
	element_position(map, game);
	game->height = height;
	game->width = ft_strlen(map[0]);
	return (game);
}

t_image	*initialize_image_struct(t_game *game)
{
	t_image	*textures;

	textures = ft_calloc(1, sizeof(t_image));
	if (textures == NULL)
		error_message("Memory Allocation Failed");
	textures = add_floor_texture(game->mlx, textures);
	textures = add_wall_texture(game->mlx, textures);
	textures = add_exit_texture(game->mlx, textures);
	textures = add_collectable_texture(game->mlx, textures);
	textures = add_player_texture(game->mlx, textures);
	return (textures);
}
