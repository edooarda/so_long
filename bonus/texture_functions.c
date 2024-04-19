/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:31:13 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 13:14:55 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*add_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero;

	hero = mlx_load_png("texture/ms_moo_wait.png");
	if (hero == NULL)
		error_message("Problem with loading P.Image");
	image->player = mlx_texture_to_image(mlx, hero);
	if (image->player == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero);
	return (image);
}

t_image	*add_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("texture/exit_open.png");
	if (exit == NULL)
		error_message("Problem with loading E.Image");
	image->exit = mlx_texture_to_image(mlx, exit);
	if (image->exit == NULL)
		error_message("Problem adding texture E.Image");
	mlx_delete_texture(exit);
	return (image);
}

t_image	*add_collectable_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collect;

	collect = mlx_load_png("texture/mushroom.png");
	if (collect == NULL)
		error_message("Problem with loading C.Image");
	image->collect = mlx_texture_to_image(mlx, collect);
	if (image->collect == NULL)
		error_message("Problem adding texture C.Image");
	mlx_delete_texture(collect);
	return (image);
}

t_image	*add_wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("texture/tree.png");
	if (wall == NULL)
		error_message("Problem with loading W.Image");
	image->wall = mlx_texture_to_image(mlx, wall);
	if (image->wall == NULL)
		error_message("Problem adding texture W.Image");
	mlx_delete_texture(wall);
	return (image);
}

t_image	*add_floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("texture/grass.png");
	if (grass == NULL)
		error_message("Problem with loading F.Image");
	image->floor = mlx_texture_to_image(mlx, grass);
	if (image->floor == NULL)
		error_message("Problem adding texture F.Image");
	mlx_delete_texture(grass);
	return (image);
}
