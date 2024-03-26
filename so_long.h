/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:40 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/26 14:48:17 by edribeir      ########   odam.nl         */
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

typedef struct s_game
{
	char	**game;
	int		height;
	int		width;
} t_game;

char	*read_map(char *map);
void	str_map_checkers(char *map);
void	array_map_checkers(char **array_map);

// File Functions
void	checker_file_extension(char *file);
void turn_file_into_data(char *argv);

#endif