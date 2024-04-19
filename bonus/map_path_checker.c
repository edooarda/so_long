/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_path_checker.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/15 10:59:57 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 13:42:50 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	check_path(t_game *temp, int y, int x)
{
	if (temp->map[y][x] == '1' || temp->map[y][x] == 'S')
		return ;
	if (temp->map[y][x] == 'E')
		temp->exit_position_x = 1;
	if (temp->map[y][x] == 'C')
		temp->collectable--;
	temp->map[y][x] = '1';
	check_path(temp, y + 1, x);
	check_path(temp, y - 1, x);
	check_path(temp, y, x + 1);
	check_path(temp, y, x - 1);
}

static t_game	temp_creation(char **map, int height)
{
	t_game	temp;
	int		i;

	temp.collectable = collectable_counter(map);
	element_position(map, &temp);
	temp.height = height;
	temp.map = (char **)ft_calloc(height, sizeof(char *));
	if (temp.map == NULL)
	{
		free_map(map, height);
		free_map(temp.map, temp.height);
		error_message("Memory Allocation Fail");
	}
	i = 0;
	while (i < height)
	{
		temp.map[i] = ft_strdup(map[i]);
		i++;
	}
	return (temp);
}

void	path_finder_checker(char **map, int height)
{
	t_game	temp;

	temp = temp_creation(map, height);
	check_path(&temp, temp.player_position_y, temp.player_position_x);
	if (temp.exit_position_x != 1 || temp.collectable != 0)
	{
		free_map(map, height);
		free_map(temp.map, temp.height);
		error_message("No valid path available");
	}
	free_map(temp.map, temp.height);
}
