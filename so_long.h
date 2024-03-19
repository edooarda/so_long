/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:40 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/19 17:18:00 by edribeir      ########   odam.nl         */
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

char	*read_map(char *map);
void	map_checkers(char *map);
void	checker_file_extension(char *file);

#endif