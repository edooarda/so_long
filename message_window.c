/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message_window.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 12:11:39 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 12:54:43 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_to_screen(t_game *game)
{
	mlx_put_string(game->mlx, "MOVES:",
		16, game->height * 64);
	game->textures->collect_window = mlx_put_string(game->mlx,
			"MISSING COLLECTABLE:", 160, game->height * 64);
}

void	msg_collectable_screen(t_game *game)
{
	char	*str;

	str = ft_itoa(game->collectable);
	mlx_delete_image(game->mlx, game->textures->img_collect);
	game->textures->img_collect = mlx_put_string(game->mlx,
			str, 364, game->height * 64);
	if (game->collectable == 0)
	{
		mlx_delete_image(game->mlx, game->textures->collect_window);
		mlx_delete_image(game->mlx, game->textures->img_collect);
		game->textures->img_collect = mlx_put_string(game->mlx,
				"Ms. MOO is very happy!!! GO HOME!", 175, game->height * 64);
	}
	free(str);
}

void	msg_moves_screen(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->textures->img_moves);
	game->textures->img_moves = mlx_put_string(game->mlx,
			str, 80, game->height * 64);
	free(str);
}
