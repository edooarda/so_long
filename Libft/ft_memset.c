/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:25:18 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/26 09:46:29 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t nbytes)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < nbytes)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

// int main()
// {
//     char s[] = "Little String";
//     int t = '0';
//     int num = 3;
//     char *m = ft_memset(s, t, num);
//     printf("%s", m);
// }
// s = "hello word"
// int = 65;
// size_t = 3;

// "AAAlo World"