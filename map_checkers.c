/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checkers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 17:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/19 17:19:09 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_empty_map(char *map)
{
	if(map[0] == '\0')
	{
		ft_printf("Error\nEmpty Map, please try a different file\n");
		exit(EXIT_FAILURE);
	}

}

void	map_checkers(char *map)
{
	check_empty_map(map);
}