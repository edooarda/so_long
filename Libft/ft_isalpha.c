/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:42:06 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 11:18:57 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	if ((c >= 'a' && c <= 'z'))
		return (2);
	else
		return (0);
}

// int main()
// {
//     char c;
//     // int c;
//     c = 'T';
//     // c = 65;
//     printf ("Result when is upper case: %d", ft_isalpha(c));

//     c = 't';
//     printf("\nResult when is lowercase: %d", ft_isalpha(c));

//     c= '+';
//     printf("\nResult when is non-alphabetic: %d", ft_isalpha(c));
// }