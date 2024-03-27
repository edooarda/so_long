/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:40 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/27 18:24:57 by edribeir      ########   odam.nl         */
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

typedef struct s_game
{
	int		moves;
	int		collectable;
	int		player_position_x;
	int		player_position_y;
	int		exit_position_x;
	int		exit_position_y;
	int		height;
	int		width;
	mlx_t	*mlx;
} t_game;

typedef struct s_image
{
	mlx_image_t			*floor;
	mlx_image_t			*bonus;
	mlx_image_t			*rock;
	mlx_image_t			*clock;
	mlx_image_t			*exit;
	mlx_image_t			*player_up;
	mlx_image_t			*player_down;
	mlx_image_t			*player_right;
	mlx_image_t			*player_left;
	mlx_image_t			*player_wait;
	mlx_image_t			*enemy;
} t_image;

void	error_message(char *message);
char	*read_map(char *map);

// Checkers
void	str_map_checkers(char *map);
int		array_map_checkers(char **array_map);

// Data 
t_game	*turn_file_into_data(char *argv);
t_game	*initialize_game_struct(char **map, int height);
t_game	*element_position(char **map, t_game *game);
t_game	*collectible_counter(char **map, t_game *game);

#endif