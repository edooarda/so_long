/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_sprites.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 17:05:07 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/18 18:06:35 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	*add_player_direction_texture_2(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero_left;
	mlx_texture_t	*hero_right;

	hero_left = mlx_load_png("texture/hero_left.png");
	if (hero_left == NULL)
		error_message("Problem with loading P.Image");
	image->p_left = mlx_texture_to_image(mlx, hero_left);
	if (image->p_left == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_left);
	hero_right = mlx_load_png("texture/hero_right.png");
	if (hero_right == NULL)
		error_message("Problem with loading P.Image");
	image->p_right = mlx_texture_to_image(mlx, hero_right);
	if (image->p_right == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_right);
	return (image);
}

t_image	*add_player_direction_texture_y(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero_up;
	mlx_texture_t	*hero_down;

	hero_up = mlx_load_png("texture/hero_up.png");
	if (hero_up == NULL)
		error_message("Problem with loading P.Image");
	image->p_up = mlx_texture_to_image(mlx, hero_up);
	if (image->p_up == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_up);
	hero_down = mlx_load_png("texture/hero_down.png");
	if (hero_down == NULL)
		error_message("Problem with loading P.Image");
	image->p_down = mlx_texture_to_image(mlx, hero_down);
	if (image->p_down == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_down);
	image = add_player_direction_texture_2(mlx, image);
	return (image);
}

static void	direction_texture_y(t_game *game, char c)
{
	if (c == 'U')
	{
		game->textures->player->instances->enabled = false;
		disable_sprites(game);
		game->textures->p_up->instances->enabled = true;
		game->textures->player->instances->y -= PIXELS;
		game->textures->p_down->instances->y -= PIXELS;
		game->textures->p_right->instances->y -= PIXELS;
		game->textures->p_left->instances->y -= PIXELS;
		game->textures->p_up->instances->y -= PIXELS;
	}
	else if (c == 'D')
	{
		game->textures->player->instances->enabled = false;
		disable_sprites(game);
		game->textures->p_down->instances->enabled = true;
		game->textures->player->instances->y += PIXELS;
		game->textures->p_up->instances->y += PIXELS;
		game->textures->p_down->instances->y += PIXELS;
		game->textures->p_right->instances->y += PIXELS;
		game->textures->p_left->instances->y += PIXELS;
	}
}

void	direction_texture(t_game *game, char c)
{
	if (c == 'L')
	{
		game->textures->player->instances->enabled = false;
		disable_sprites(game);
		game->textures->p_left->instances->enabled = true;
		game->textures->player->instances->x -= PIXELS;
		game->textures->p_left->instances->x -= PIXELS;
		game->textures->p_up->instances->x -= PIXELS;
		game->textures->p_down->instances->x -= PIXELS;
		game->textures->p_right->instances->x -= PIXELS;
	}
	else if (c == 'R')
	{
		game->textures->player->instances->enabled = false;
		disable_sprites(game);
		game->textures->p_right->instances->enabled = true;
		game->textures->player->instances->x += PIXELS;
		game->textures->p_right->instances->x += PIXELS;
		game->textures->p_up->instances->x += PIXELS;
		game->textures->p_down->instances->x += PIXELS;
		game->textures->p_left->instances->x += PIXELS;
	}
	else
		direction_texture_y(game, c);
}

void	disable_sprites(t_game *game)
{
	game->textures->p_left->instances->enabled = false;
	game->textures->p_right->instances->enabled = false;
	game->textures->p_down->instances->enabled = false;
	game->textures->p_up->instances->enabled = false;
}
