/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game_checkers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 15:54:17 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 16:33:27 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*collect_checker(int y, int x, t_game *game)
{
	size_t	cll;

	cll = 0;
	if (game->map[y][x] == 'C')
	{
		while (cll < game->textures->collect->count)
		{
			if (((game->textures->collect->instances[cll].x) / PIXELS) == x
				&& ((game->textures->collect->instances[cll].y) / PIXELS) == y)
			{
				game->textures->collect->instances[cll].enabled = false;
				game->collectable--;
				game->map[y][x] = '0';
			}
			cll++;
		}
	}
	return (game);
}

void	finish_game_checker(t_game *game)
{
	ft_printf("Moves: %i\n", game->moves);
	if (game->collectable == 0)
		ft_putendl_fd("	Ms. MOO is happy!! Go Home 🎉!", 1);
	if (game->collectable == 0
		&& game->player_position_x == game->exit_position_x
		&& game->player_position_y == game->exit_position_y)
	{
		mlx_close_window(game->mlx);
		ft_printf("\n");
		ft_putendl_fd("	Congratulations! 🥳", 1);
		ft_putendl_fd("Ms. MOO is Happy with a full belly! 🍄", 1);
		ft_putendl_fd("Do you want to play again? Try another MAP.", 1);
	}
	else if (game->player_position_x == game->exit_position_x
		&& game->player_position_y == game->exit_position_y)
	{
		ft_printf("\n");
		ft_putendl_fd("Are you missing mushrooms 🍄?", 2);
		ft_putendl_fd("Ms. MOO wants them ALL!", 2);
	}
}
