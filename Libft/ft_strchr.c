/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:45:20 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/27 11:44:14 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 0;
	while (str[i] != '\0' && str[i] != chr)
		i++;
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}

// int main()
// {
//     char str[] = "ana";
//     int ch = 'n';
//     printf("new frase: %s", ft_strchr(str, ch));
// }

//(char *)&str[i] works with (char *)str;