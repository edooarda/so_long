/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moviments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 15:11:46 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/05 18:11:16 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TO DO: change C into '0' to not be collectable again!
// need to discovery instance number position
t_game	*move_right(t_game *game)
{ 
	if (game->map[game->player_position_y][game->player_position_x + 1] != '1')
	{
		ft_printf("cenourinhas: %i\n", game->collectable);
		if (game->map[game->player_position_y][game->player_position_x + 1] == 'C')
		{
			game->textures->carrot->instances[0].enabled = false;
			game->collectable--;
		}
		ft_printf("cenourinhas: %i\n", game->collectable);
		game->textures->player->instances[0].x += PIXELS;
		game->player_position_x++;
		game->moves++;
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->map[game->player_position_y][game->player_position_x - 1] != '1')
	{
		if (game->map[game->player_position_y][game->player_position_x - 1] == 'C')
		{
			game->textures->carrot->instances[0].enabled = false;
			game->collectable--;
		}
		game->textures->player->instances[0].x -= PIXELS;
		game->player_position_x--;
		game->moves++;
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->map[game->player_position_y + 1][game->player_position_x] != '1')
	{
		if (game->map[game->player_position_y + 1][game->player_position_x] == 'C')
		{
			game->textures->carrot->enabled = false;
			game->collectable--;
		}
		game->textures->player->instances[0].y += PIXELS;
		game->player_position_y++;
		game->moves++;
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	return (game);
}

t_game	*move_up(t_game *game)
{
	if (game->map[game->player_position_y - 1][game->player_position_x] != '1')
	{
		if (game->map[game->player_position_y - 1][game->player_position_x] == 'C')
		{
			game->textures->carrot->enabled = false;
			game->collectable--;
		}
		game->textures->player->instances[0].y -= PIXELS;
		game->player_position_y--;
		game->moves++;
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	return (game);
}

void	ft_hook_moves(mlx_key_data_t keydata, void *mlx)
{
	t_game *game;

	game = (t_game *)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("Goodbye, Thanks for the Carrots! Or not...\n");
		mlx_close_window(game->mlx);
	}
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_up(mlx);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_down(mlx);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_left(mlx);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_right(mlx);
}

