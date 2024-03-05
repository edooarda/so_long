/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 09:04:32 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 17:01:36 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		final_substr;
	char		*sub_str;
	size_t		j;
	size_t		i;

	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		final_substr = 0;
	else
		final_substr = ft_strlen(s) - start;
	if (final_substr > len)
		final_substr = len;
	sub_str = (char *)malloc((final_substr + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < final_substr)
			sub_str[j++] = s[i];
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return 1;
//     // char str[] = "A";
//     char *str = argv[1];
//     char *m = ft_substr(str, ft_atoi(argv[2]), ft_atoi(argv[3]));
//     printf("%s\n", m);
// }