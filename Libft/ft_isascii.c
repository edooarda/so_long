/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:06:03 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 11:09:36 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main()
// {
// 	char t;
// 	int m;
// 	m = 255;
// 	printf("with is not in ascii: %d", ft_isascii(m));

// 	char T;
// 	t = 'A';
// 	printf("\nwith is not in ascii: %d", ft_isascii(t));
// }