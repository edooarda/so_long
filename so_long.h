/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:40 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/15 17:39:42 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

# define PIXELS 64

typedef struct s_image
{
	mlx_image_t		*floor;
	mlx_image_t		*rock;
	mlx_image_t		*exit;
	mlx_image_t		*carrot;
	mlx_image_t		*player;
}	t_image;

typedef struct s_game
{
	char		**map;
	int			moves;
	int			collectable;
	int			player_position_x;
	int			player_position_y;
	int			exit_position_x;
	int			exit_position_y;
	int			height;
	int			width;
	t_image		*textures;
	mlx_t		*mlx;
}	t_game;

void	error_message(char *message);
char	*read_map(char *map);

// Checkers
void	str_map_checkers(char *map);
int		array_map_checkers(char **array_map);
void	collect_all_collectable(t_game *game);
t_game	*collectable_instance_checker(int player_y, int player_x, t_game *game);
void	path_finder_checker(char **map, int height);

// Data 
t_game	*turn_file_into_data(char *argv);
t_game	*initialize_game_struct(char **map, int height);
t_image	*initialize_image_struct(t_game *game);
void	element_position(char **map, t_game *game);
int		collectable_counter(char **map);

//Texture 
t_image	*add_wall_texture(mlx_t *mlx, t_image *image);
t_image	*add_floor_texture(mlx_t *mlx, t_image *image);
t_image	*add_collectable_texture(mlx_t *mlx, t_image *image);
t_image	*add_exit_texture(mlx_t *mlx, t_image *image);
t_image	*add_player_texture(mlx_t *mlx, t_image *image);
void	add_texture_window(t_game *game);
void	add_floor_window(t_game *game);

// Moviments
void	ft_hook_moves(mlx_key_data_t keydata, void *mlx);

#endif