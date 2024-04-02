/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 11:48:53 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/02 15:22:31 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map)
{
	char	*current_line;
	char	*map_read;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_message("There is a problem Open the File");
	map_read = ft_calloc(1, sizeof(char));
	if (map_read == NULL)
		return (NULL);
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		map_read = ft_strjoin(map_read, current_line);
		free(current_line);
		current_line = get_next_line(fd);
	}
	close (fd);
	return (map_read);
}

t_game	*turn_file_into_data(char *argv)
{
	t_game	*game;
	char	*str_map;
	char	**array_map;
	int		height;

	str_map = read_map(argv);
	str_map_checkers(str_map);
	array_map = ft_split(str_map, '\n');
	height = array_map_checkers(array_map);
	game = initialize_game_struct(array_map, height);
	free(str_map);
	return (game);
}
