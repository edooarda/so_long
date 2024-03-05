/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:58:57 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 12:19:57 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int main()
// {
//     char c;
//     c = '\n';
//     printf("Result printable character %c is passed: %d", c, ft_isprint(c));
//     c = '\\';
//     printf("\nResult %c is passed to isprint(): %d", c, ft_isprint(c));
// }