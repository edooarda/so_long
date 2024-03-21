/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 11:48:53 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/21 13:58:42 by edribeir      ########   odam.nl         */
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
	{
		ft_printf("Error\nThere is a problem Open the File\n");
		exit (EXIT_FAILURE);
	}
	map_read = ft_calloc(1, sizeof(char));
	if (map_read == NULL)
		return (NULL);
	while ((current_line = get_next_line(fd))!= NULL)
	{
		map_read = ft_strjoin(map_read, current_line);
		free(current_line);
	}
	close (fd);
	return (map_read);
}

void turn_file_into_data(char *argv)
{
	char	*str_map;
	char	**array_map;
	
	str_map = read_map(argv);
	str_map_checkers(str_map);
	array_map = ft_split(str_map, '\n');

	int i = 0;
	while(array_map[i])
	{
		ft_printf("- %s\n",array_map[i]);
		i++;
	}
}
