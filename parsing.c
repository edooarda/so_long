/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 11:48:53 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/17 15:37:42 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map, char *map_read)
{
	char	*current_line;
	char	*temp;
	int		fd;

	temp = map_read;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_message("There is a problem Open the File");
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		map_read = ft_strjoin(temp, current_line);
		if (map_read == NULL)
			return (free(map_read), NULL);
		free(current_line);
		current_line = get_next_line(fd);
		free(temp);
		temp = map_read;
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

	str_map = ft_calloc(1, sizeof(char));
	if (str_map == NULL)
		return (NULL);
	str_map = read_map(argv, str_map);
	str_map_checkers(str_map);
	array_map = ft_split(str_map, '\n');
	height = array_map_checkers(array_map);
	game = initialize_game_struct(array_map, height);
	free(str_map);
	return (game);
}
