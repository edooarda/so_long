/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game_checkers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 15:54:17 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/18 14:18:36 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*collectable_instance_checker(int player_y, int player_x, t_game *game)
{
	size_t	collectable;

	collectable = 0;
	if (game->map[player_y][player_x] == 'C')
	{
		while (collectable < game->textures->carrot->count)
		{
			if (((game->textures->carrot->instances[collectable].x) / PIXELS) == player_x
				&& ((game->textures->carrot->instances[collectable].y) / PIXELS) == player_y)
			{
				game->textures->carrot->instances[collectable].enabled = false;
				game->collectable--;
				game->map[player_y][player_x] = '0';
			}
			collectable++;
		}
	}
	return (game);
}

void	collect_all_collectable(t_game *game)
{
	ft_printf("Moves: %i\n", game->moves);
	if (game->collectable == 0)
		ft_printf("Mr Rabbit is happy!! Go Home 🎉!\n");
	if (game->collectable == 0
		&& game->player_position_x == game->exit_position_x
		&& game->player_position_y == game->exit_position_y)
	{
		mlx_close_window(game->mlx);
		ft_printf("\n");
		ft_putendl_fd("	Congratulations! 🥳", 1);
		ft_putendl_fd("Mr. Rabbit is Happy with a full belly! 🥕", 1);
		ft_putendl_fd("Do you want to play again? Try another MAP.", 1);
	}
	else if (game->player_position_x == game->exit_position_x
		&& game->player_position_y == game->exit_position_y)
	{
		ft_printf("\n");
		ft_putendl_fd("Are you missing carrots 🥕? Mr Rabbit wants them ALL!", 2);
	}
	touch_enemies(game, game->player_position_y, game->player_position_x);
}
