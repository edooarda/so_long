/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_path_checker.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/15 10:59:57 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/15 17:53:07 by edribeir      ########   odam.nl         */
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

static int	check_path(t_game *temp, int x, int y)
{
	if (temp->map[x][y] == '1')
	{
		printf("position player [%i][%i]\n",y, x);
		printf("			WaLL\n");
		return (0);
	}
	if (temp->map[x][y] == 'C')
	{
		printf("			Less Carrot\n");
		temp->collectable--;
	}
	if (temp->map[x][y] == 'E')
	{
		printf("			Exit here\n");
		temp->exit_position_x = 1;
		return (0);
	}
	temp->map[x][y] = '1';
	printf("			Change for 1!!!\n");
	printf("position player [%i][%i]\n",y, x);
	if (check_path(temp, y + 1, x))
	{
		printf("			UP\n");
		return (1);
	}
	if (check_path(temp, y - 1, x))
	{
		printf("			Down\n");
		return (1);
	}
	if (check_path(temp, y, x + 1))
	{
		printf("			Right\n");
		return (1);
	}
	if (check_path(temp, y, x - 1))
	{
		printf("			Left\n");
		return (1);
	}
	return (0);
}

void	path_finder_checker(char **map, int height)
{
	t_game	temp;
	int		i;


	temp.collectable = collectable_counter(map);
	element_position(map, &temp);
	temp.height = height;
	temp.exit_position_x = 0;
	temp.map = (char **)ft_calloc(height, sizeof(char *));
	if (temp.map == NULL)
		error_message("Memory Allocation Fail");
	i = 0;
	while (i < height)
	{
		temp.map[i] = ft_strdup(map[i]);
		printf("		%s\n", temp.map[i]);
		i++;
	}
	printf("position player first[%i][%i]\n",temp.player_position_y, temp.player_position_x);
	check_path(&temp, temp.player_position_x, temp.player_position_y);
	if (!(temp.exit_position_x == 1 && temp.collectable == 0))
		error_message("No valid path available");
	free_map(temp.map, temp.height);
}