/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:02:14 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/12 18:04:17 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*combine_strs(char *p_line, char *buf)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p_line == NULL || buf == NULL)
		return (NULL);
	joined = malloc((get_length(p_line) + get_length(buf) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (p_line[i] != '\0')
		joined[j++] = p_line[i++];
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		joined[j++] = buf[i++];
	if (buf[i] == '\n')
		joined[j++] = buf[i];
	joined[j] = '\0';
	return (joined);
}
