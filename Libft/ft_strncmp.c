/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:43:39 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 16:44:35 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//     char a[] = "world";
//     char b[] = "hello";
//     char result = strncmp(a, b, 2);
//     printf("%d original function", result);
//     char result2 = ft_strncmp(a, b, 2);
//     printf("\n%d", result2);
//     return (0);
// }
