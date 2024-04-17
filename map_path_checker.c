/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_path_checker.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/15 10:59:57 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/17 12:13:21 by edribeir      ########   odam.nl         */
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
	// printf("position player first[%i][%i]\n", y, x);
	if (temp->map[y][x] == '1' || temp->map[y][x] == 'E')
	{
		if (temp->map[y][x] == 'E')
			temp->exit_position_x = 1;
		return ;
	}
	if (temp->map[y][x] == 'C')
		temp->collectable--;
	temp->map[y][x] = '1';
	// printf("			Change for 1!!!\n");
	// printf("position player [%i][%i]\n", y, x);
	check_path(temp, y + 1, x);
	check_path(temp, y - 1, x);
	check_path(temp, y, x + 1);
	check_path(temp, y, x - 1);
}

void	path_finder_checker(char **map, int height)
{
	t_game	temp;
	int		i;

	temp.collectable = collectable_counter(map);
	element_position(map, &temp);
	temp.height = height;
	temp.map = (char **)ft_calloc(height, sizeof(char *));
	if (temp.map == NULL)
		error_message("Memory Allocation Fail");
	i = 0;
	while (i < height)
	{
		temp.map[i] = ft_strdup(map[i]);
		// printf("		%s\n", temp.map[i]);
		i++;
	}
	check_path(&temp, temp.player_position_y, temp.player_position_x);
	if (temp.exit_position_x != 1 || temp.collectable != 0)
		error_message("No valid path available");
	free_map(temp.map, temp.height);
}
