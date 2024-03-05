/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:12:22 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 18:36:41 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t nbytes)
{
	unsigned char	*pointer;
	unsigned char	tofind;

	pointer = (unsigned char *)s;
	tofind = (unsigned char)c;
	while (nbytes > 0)
	{
		if (*pointer == tofind)
			return ((void *)pointer);
		nbytes--;
		pointer++;
	}
	return (NULL);
}

// int main()
// {
//     const char str[] = "MmARIA";
//     const char ch = 'A';
//     printf("%s\n", (char *)ft_memchr(str, ch, 3));
//     printf("%s", (char *)memchr(str, ch, 3));
// }