/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_map_checkers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 11:30:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/26 18:03:15 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	array_map_wall(int height, char **array_map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = (ft_strlen(array_map[0]) - 1);
	while (array_map[j])
	{
		while (array_map[j][i])
		{
			if (array_map[0][i] != '1' || array_map[height - 1][i] != '1')
			{
				ft_printf("ERROR\nThe Map is not surrounded by Walls\n");
				exit (EXIT_FAILURE);
			}
			i++;
		}
		if (array_map[j][0] != '1' || array_map[j][len] != '1')
		{
			ft_printf("ERROR\nThe Map is not surrounded by Walls\n");
			exit (EXIT_FAILURE);
		}
		j++;
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
		{
			ft_printf("ERROR\nMap is Not a Retangular Shape\n");
			exit (EXIT_FAILURE);
		}
		line++;
	}
	return (line);
}

void	array_map_checkers(char **array_map)
{
	int	height;

	height = array_map_shape(array_map);
	array_map_wall(height, array_map);
}
