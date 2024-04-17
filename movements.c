/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 15:11:46 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/17 18:33:04 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*move_right(t_game *game)
{ 
	if (game->map[game->player_position_y][game->player_position_x + 1] != '1')
	{
		game->textures->player->instances[0].x += PIXELS;
		game->player_position_x++;
		game->moves++;
		collectable_instance_checker(game->player_position_y, game->player_position_x, game);
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	direction_texture(game, 'R');
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->map[game->player_position_y][game->player_position_x - 1] != '1')
	{
		game->textures->player->instances[0].x -= PIXELS;
		game->player_position_x--;
		game->moves++;
		collectable_instance_checker(game->player_position_y, game->player_position_x, game);
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	direction_texture(game, 'L');
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->map[game->player_position_y + 1][game->player_position_x] != '1')
	{
		game->textures->player->instances[0].y += PIXELS;
		game->player_position_y++;
		game->moves++;
		collectable_instance_checker(game->player_position_y, game->player_position_x, game);
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	direction_texture(game, 'D');
	return (game);
}

t_game	*move_up(t_game *game)
{
	if (game->map[game->player_position_y - 1][game->player_position_x] != '1')
	{
		game->textures->player->instances[0].y -= PIXELS;
		game->player_position_y--;
		game->moves++;
		collectable_instance_checker(game->player_position_y, game->player_position_x, game);
	}
	else
		ft_putendl_fd("Yeow! That hurts!", 1);
	collect_all_collectable(game);
	direction_texture(game, 'U');
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
	msg_moves_screen(game);
	msg_collectable_screen(game);
}

