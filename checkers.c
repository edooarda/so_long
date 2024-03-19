/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 14:47:09 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/19 17:13:36 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_file_extension(char *file)
{
	int	len;
	
	len = ft_strlen(file);
	if(len < 4 || ft_strncmp(&file[len - 4], ".ber", 4))
	{
		ft_printf("Error\nPlease, use a .ber file for the Map\n");
		exit (EXIT_FAILURE);
	}
}

