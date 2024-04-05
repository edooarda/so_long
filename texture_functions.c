/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 13:31:13 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/05 11:48:37 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*add_player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero_wait;
	mlx_texture_t	*hero_up;
	mlx_texture_t	*hero_down;
	mlx_texture_t	*hero_right;
	mlx_texture_t	*hero_left;

	hero_wait = mlx_load_png("texture/hero_wait.png");
	if (hero_wait == NULL)
		error_message("Problem with loading P.Image");
	image->player_wait = mlx_texture_to_image(mlx, hero_wait);
	if (image->player_wait == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_wait);

	hero_up = mlx_load_png("texture/hero_up.png");
	if (hero_up == NULL)
		error_message("Problem with loading PU.Image");
	image->player_up = mlx_texture_to_image(mlx, hero_up);
	if (image->player_up == NULL)
		error_message("Problem adding texture PU.Image");
	mlx_delete_texture(hero_up);

	hero_down = mlx_load_png("texture/hero_down.png");
	if (hero_down == NULL)
		error_message("Problem with loading PD.Image");
	image->player_down = mlx_texture_to_image(mlx, hero_down);
	if (image->player_down == NULL)
		error_message("Problem adding texture PD.Image");
	mlx_delete_texture(hero_down);

	hero_right = mlx_load_png("texture/hero_right.png");
	if (hero_right == NULL)
		error_message("Problem with loading PR.Image");
	image->player_right = mlx_texture_to_image(mlx, hero_right);
	if (image->player_right == NULL)
		error_message("Problem adding texture PR.Image");
	mlx_delete_texture(hero_right);

	hero_left = mlx_load_png("texture/hero_left.png");
	if (hero_left == NULL)
		error_message("Problem with loading PL.Image");
	image->player_left = mlx_texture_to_image(mlx, hero_left);
	if (image->player_left == NULL)
		error_message("Problem adding texture PL.Image");
	mlx_delete_texture(hero_left);

	return (image);
}

t_image	*add_exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hole;

	hole = mlx_load_png("texture/exit.png");
	if (hole == NULL)
		error_message("Problem with loading E.Image");
	image->exit = mlx_texture_to_image(mlx, hole);
	if (image->exit == NULL)
		error_message("Problem adding texture E.Image");
	mlx_delete_texture(hole);
	return (image);
}

t_image	*add_collectable_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*carrot;

	carrot = mlx_load_png("texture/carrot.png");
	if (carrot == NULL)
		error_message("Problem with loading C.Image");
	image->carrot = mlx_texture_to_image(mlx, carrot);
	if (image->carrot == NULL)
		error_message("Problem adding texture C.Image");
	mlx_delete_texture(carrot);
	return (image);
}

t_image	*add_wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*rock;

	rock = mlx_load_png("texture/rock.png");
	if (rock == NULL)
		error_message("Problem with loading W.Image");
	image->rock = mlx_texture_to_image(mlx, rock);
	if (image->rock == NULL)
		error_message("Problem adding texture W.Image");
	mlx_delete_texture(rock);
	return (image);
}

t_image	*add_floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("texture/floor.png");
	if (grass == NULL)
		error_message("Problem with loading F.Image");
	image->floor = mlx_texture_to_image(mlx, grass);
	if (image->floor == NULL)
		error_message("Problem adding texture F.Image");
	mlx_delete_texture(grass);
	return (image);
}
