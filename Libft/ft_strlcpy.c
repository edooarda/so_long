/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 10:00:18 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 16:46:05 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	char	*p_src;

	i = 0;
	p_src = (char *)src;
	if (destsize == 0)
		return (ft_strlen(src));
	while (i < (destsize - 1) && p_src[i] != '\0')
	{
		dst[i] = p_src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int main()
// {
//     char source[] = "hello";
//     char dest[6] = "Maria";
//     int f=ft_strlcpy(dest, source, 0);
//     printf("%d", f);
// }