/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 09:51:50 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 10:54:27 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char *largestring = "Foo Bar Baz";
//     char *smallstring = " BBar";
//     char *ptr;
//     // char *ptr1;
//     ptr = ft_strnstr(largestring, smallstring, 5);
//     printf("%s", ptr);
//     // ptr1 = strnstr(largestring, smallstring, 5);
//     // printf("\n%s", ptr1);
// }
