/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemies.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 12:10:58 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/18 14:50:41 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy_window(t_game *game, int line, int col)
{
	if (mlx_image_to_window(game->mlx, game->textures->enemy,
				col * PIXELS, line * PIXELS) < 0)
			error_message("Failed to put exit image to window");
}
t_image	*add_enemy_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("texture/enemy.png");
	if (enemy == NULL)
		error_message("Problem with loading P.Image");
	image->enemy = mlx_texture_to_image(mlx, enemy);
	if (image->enemy == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(enemy);
	return (image);
}

void	touch_enemies(t_game *game, int player_y, int player_x)
{
	if (game->map[player_y][player_x] == 'S')
	{
		ft_putendl_fd("\n	Mr Rabbit is dead 💀", 1);
		ft_putendl_fd("\nTry again OR change MAP", 1);
		usleep(400000);
		mlx_close_window(game->mlx);
	}
}
