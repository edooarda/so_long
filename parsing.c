/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 11:48:53 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/19 16:42:34 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map) // there is another way of doing the while without a break?
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
	while (fd)
	{
		current_line = get_next_line(fd);
		if(current_line != NULL)
		{
			map_read = ft_strjoin(map_read, current_line);
			free(current_line);
		}
		else
			break ;
	}
	close (fd);
	return (map_read);
}
