/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:29:28 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 11:04:28 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int main()
// {
//     char c;
//     c='8';
//     printf("Result when numeric character is passed: %d", ft_isdigit(c));
//     c='E';
//     printf("\nResult when non-numeric %d", ft_isdigit(c));
// }