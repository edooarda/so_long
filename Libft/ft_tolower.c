/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:36:38 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/25 09:42:16 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

// int main()
// {
//     int c;
//     c = 'a';
//     printf("%c -> %c", c, ft_tolower(c));
//     c = 'B';
//     printf("\n%c -> %c", c, ft_tolower(c));
//     c = 'E';
//     printf("\n%c -> %c", c, ft_tolower(c));
//     c = '9';
//     printf("\n%c -> %c", c, ft_tolower(c));
// }