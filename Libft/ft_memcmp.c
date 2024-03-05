/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 17:32:56 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/26 11:42:26 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t nbytes)
{
	unsigned char	*buff1;
	unsigned char	*buff2;
	size_t			i;

	buff1 = (unsigned char *)str1;
	buff2 = (unsigned char *)str2;
	i = 0;
	while (i < nbytes)
	{
		if (buff1[i] != buff2[i])
			return (buff1[i] - buff2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//     char str[] = "world";
//     char str_1[] = "worello";
//     // char str[] = "2234567";
//     // char str_1[] = "822222";
//     int result = ft_memcmp(str, str_1, 4);
//     printf("%d", result);
//     int resul2 = memcmp(str, str_1, 4);
//     printf("\n%d", resul2);
// }