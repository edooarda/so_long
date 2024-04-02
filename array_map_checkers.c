/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_map_checkers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 11:30:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/02 10:59:45 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	array_map_wall(int height, char **array_map)
{
	int	col;
	int	line;
	int	len;

	line = 0;
	len = (ft_strlen(array_map[0]) - 1);
	while (array_map[line])
	{
		col = 0;
		while (array_map[line][col])
		{
			if (array_map[0][col] != '1' || array_map[height - 1][col] != '1')
				error_message("The Map is not surrounded by Walls");
			col++;
		}
		if (array_map[line][0] != '1' || array_map[line][len] != '1')
			error_message("The Map is not surrounded by Walls");
		line++;
	}
}

static int	array_map_shape(char **array_map)
{
	int		line;
	size_t	len_line;

	line = 0;
	len_line = ft_strlen(array_map[line]);
	while (array_map[line])
	{
		if (ft_strlen(array_map[line]) != len_line)
			error_message("Map is Not a Retangular Shape");
		line++;
	}
	return (line);
}

int	array_map_checkers(char **array_map)
{
	int	height;

	height = array_map_shape(array_map);
	array_map_wall(height, array_map);
	// TO DO: CHECK WITH there is a viable Path

	return (height);
}
