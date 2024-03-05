/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:44:12 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 16:23:24 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len + 1)
	{
		while ((src[i] != '\0') && ((dst_len + 1 + i) < dstsize))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		return (dst_len + src_len);
}

// int main()
// {
//     char source[] = "Catnip";
//     char dest[] = "Whiskas Sache";
//     int j = ft_strlcat(dest, source, 5);
//     printf("%s and the number of new dest %d", dest, j);
//     j = strlcat(dest, source, 5); // compile with -lbsd
//     printf("\n%s, %d", dest, j);
// }
