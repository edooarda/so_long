/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:01:53 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/21 12:17:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_buffer(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strchr(buffer, '\n');
	if (tmp == NULL)
		return ;
	tmp++;
	while (tmp[i] != '\0')
	{
		buffer[i] = tmp[i];
		i++;
	}
	buffer[i] = '\0';
}

char	*insert_remainder(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((get_length(buffer) + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_and_join(int fd, char *buffer, char *line)
{
	int		bytes_read;
	char	*prev_line;

	bytes_read = 1;
	prev_line = line;
	if (ft_strchr(line, '\n') != NULL)
		return (line);
	while (ft_strchr(buffer, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[0] = '\0';
			return (free(prev_line), NULL);
		}
		buffer[bytes_read] = '\0';
		line = combine_strs(prev_line, buffer);
		if (line == NULL)
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = insert_remainder(buffer);
	if (line == NULL)
		return (NULL);
	line = read_and_join(fd, buffer, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
		return (free(line), NULL);
	manage_buffer(buffer);
	return (line);
}
