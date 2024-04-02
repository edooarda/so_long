/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moviments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 15:11:46 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/02 17:36:44 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_moves(mlx_key_data_t keydata, void *mlx)
{
	t_game *game;

	game = (t_game *)mlx;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		
	}
}

