/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:40 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 17:26:37 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../Libft/libft.h"
# include "../Libft/ft_printf.h"
# include "../Libft/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

# define PIXELS 64

typedef struct s_image
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*collect;
	mlx_image_t		*player;
	mlx_image_t		*p_up;
	mlx_image_t		*p_down;
	mlx_image_t		*p_right;
	mlx_image_t		*p_left;
	mlx_image_t		*img_moves;
	mlx_image_t		*img_collect;
	mlx_image_t		*collect_window;
	mlx_image_t		*enemy;
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

// Checkers
void	str_map_checkers(char *map);
int		array_map_checkers(char **array_map);
void	finish_game_checker(t_game *game);
t_game	*collect_checker(int y, int x, t_game *game);
void	path_finder_checker(char **map, int height);

// Data
t_game	turn_file_into_data(char *argv);
t_game	initialize_game_struct(char **map, int height);
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

// Messages
void	error_message(char *message);
void	message_to_screen(t_game *game);
void	msg_moves_screen(t_game *game);
void	msg_collectable_screen(t_game *game);

//
void	free_map(char **map, int height);

// Bonus
t_image	*add_player_direction_texture_y(mlx_t *mlx, t_image *image);
void	direction_texture(t_game *game, char c);
void	disable_sprites(t_game *game);
t_image	*add_enemy_texture(mlx_t *mlx, t_image *image);
void	add_enemy_window(t_game *game, int line, int col);
void	touch_enemies(t_game *game, int player_y, int player_x);

#endif