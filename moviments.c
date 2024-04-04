/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moviments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 15:11:46 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/04 18:35:41 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*move_right(t_game *game)
{
	ft_printf("this is old player position %i\n", game->player_position_x);
	game->textures->player_wait->instances[0].x += PIXELS;
	game->player_position_x++;
	ft_printf("this is new player position %i\n", game->player_position_x);
	return (game);
}

t_game	*move_left(t_game *game)
{
	ft_printf("this is old player position %i\n", game->player_position_x);
	game->textures->player_wait->instances[0].x -= PIXELS;
	game->player_position_x--;
	ft_printf("this is new player position %i\n", game->player_position_x);
	return (game);
}

t_game	*move_down(t_game *game)
{
	ft_printf("this is old player position %i\n", game->player_position_y);
	game->textures->player_wait->instances[0].y += PIXELS;
	game->player_position_y++;
	ft_printf("this is new player position %i\n", game->player_position_y);
	return (game);
}

t_game	*move_up(t_game *game)
{
	ft_printf("this is old player position %i\n", game->player_position_y);

	game->textures->player_wait->instances[0].y -= PIXELS;
	game->player_position_y--;
	ft_printf("this is new player position %i\n", game->player_position_y);
	return (game);
}

void	ft_hook_moves(mlx_key_data_t keydata, void *mlx)
{
	t_game *game;

	game = (t_game *)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("It's time to say bye, Thanks for the fish!\n");
		mlx_close_window(game->mlx);
	}
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
	{
		move_up(mlx);
		ft_printf("press w\n");
	}
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
	{
		move_down(mlx);
		ft_printf("press s\n");
	}
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
	{
		move_left(mlx);
		ft_printf("press a\n");
	}
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
	{
		move_right(mlx);
		ft_printf("press d\n");
	}
}

