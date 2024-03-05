/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 09:08:33 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 09:43:12 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t nbytes)
{
	size_t	i;

	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	if (dst <= src)
	{
		while (nbytes > i)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (nbytes > 0)
		{
			((char *)dst)[nbytes - 1] = ((char *)src)[nbytes - 1];
			nbytes--;
		}
	}
	return (dst);
}

// int main()
// {
//     // char source[] = {1, 2, 3, 4, 6};
//     // char destin[8];
// 	char source[] = "Hello Squirtle";
//     char destin[] = "Change";
// 	printf("dest before %s\n", destin);
// 	ft_memmove(destin, source, 3);
// //    char *m = memmove(destin, source, 3);
//     // int j = 0;
//     // while (destin[j])
//     //     printf("%d", destin[j++]);
// 	printf("destin next %s", destin);
// }
