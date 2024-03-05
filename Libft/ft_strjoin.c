/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 11:20:44 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 12:15:17 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_newstr = ft_strlen(s1)+ ft_strlen(s2);
	newstr = (char *)malloc((len_newstr + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

// int main()
// {
//     // char str2[] = "Hello";
//     // char str1[] = "";
//     char str1[] = "Hello";
//     char str2[] = "Sunshine";
//     char *m = ft_strjoin(str1, str2);
//     printf("%s", m);
// }
