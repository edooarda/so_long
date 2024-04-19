/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_window_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 14:28:44 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 17:19:18 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_floor_window(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->textures->floor,
					col * PIXELS, line * PIXELS) < 0)
				error_message("Failed to put wall image to window");
			col++;
		}
		line++;
	}
}

static void	add_player_direction_textures(t_game *game, int line, int col)
{
	if (mlx_image_to_window(game->mlx, game->textures->player,
			col * PIXELS, line * PIXELS) < 0)
		error_message("Failed to put hero image to window");
	if (mlx_image_to_window(game->mlx, game->textures->p_up,
			col * PIXELS, line * PIXELS) < 0)
		error_message("Failed to put hero image to window");
	if (mlx_image_to_window(game->mlx, game->textures->p_down,
			col * PIXELS, line * PIXELS) < 0)
		error_message("Failed to put hero image to window");
	if (mlx_image_to_window(game->mlx, game->textures->p_left,
			col * PIXELS, line * PIXELS) < 0)
		error_message("Failed to put hero image to window");
	if (mlx_image_to_window(game->mlx, game->textures->p_right,
			col * PIXELS, line * PIXELS) < 0)
		error_message("Failed to put hero image to window");
}

static void	add_texture_character(t_game *game, int line, int col)
{
	if (game->map[line][col] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->textures->wall,
				col * PIXELS, line * PIXELS) < 0)
			error_message("Failed to put wall image to window");
	}
	else if (game->map[line][col] == 'P')
	{
		add_player_direction_textures(game, line, col);
		disable_sprites(game);
	}
	else if (game->map[line][col] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->textures->collect,
				col * PIXELS, line * PIXELS) < 0)
			error_message("Failed to put collectable image to window");
	}
	else if (game->map[line][col] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->textures->exit,
				col * PIXELS, line * PIXELS) < 0)
			error_message("Failed to put exit image to window");
	}
	else if (game->map[line][col] == 'S')
		add_enemy_window(game, line, col);
}

void	add_texture_window(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (line < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			add_texture_character(game, line, col);
			col++;
		}
		line++;
	}
}
