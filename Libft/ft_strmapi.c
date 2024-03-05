/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 11:39:26 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 12:17:45 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s)+ 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// char tester(unsigned int i, char c)
// {
// 	if ( i % 2 == 0)
// 	{
// 		if (c >= 'A' && c <= 'Z')
// 			c = c + 32;
// 	}
// 	return (c);
// }

// int main()
// {
// 	char s[] = "HellO";
//     char *f = ft_strmapi(s, &tester);
//     printf("%s", f);
// }