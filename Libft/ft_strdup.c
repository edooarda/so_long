/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 10:37:43 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 17:19:12 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;

	len = ft_strlen(str) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, len);
	return (dup);
}

// int main()
// {
//     char s[] = "Codam Coder";
//     char *t = ft_strdup(s);
//     printf("%s\n", t);
// 	printf("%s\n", strdup(s));
// }
