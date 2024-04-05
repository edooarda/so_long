/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game_checkers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 15:54:17 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/05 18:02:04 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_picked(t_game *game, int y, int x)
{
	int collectable;

	collectable = 0;
	while (collectable < game->collectable)
	{
		if (game->textures->carrot->instances[game->collectable].x == x
			&& game->textures->carrot->instances[game->collectable].y == y)
		{
			game->textures->carrot->instances[game->collectable].enabled = false;
		}
		collectable++;
	}
}

void	collect_all_collectable(t_game *game)
{
	ft_printf("Moves: %i\n", game->moves);
	if (game->collectable == 0 && game->player_position_x == game->exit_position_x
		&& game->player_position_y == game->exit_position_y)
	{
		mlx_close_window(game->mlx);
		ft_putendl_fd("Congratulations!", 1);
		ft_putendl_fd("Mr. Rabbit is Happy with a full belly!", 1);
		ft_putendl_fd("Do you want to play again? Try another MAP.", 1);
	}
	else if (game->player_position_x == game->exit_position_x && game->player_position_y == game->exit_position_y)
		ft_putendl_fd("Are you missing carrots? Mr Rabbit wishes them ALL!", 2);
} 