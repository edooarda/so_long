/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 14:26:06 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 14:10:51 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;
	int		start;
	int		end;

	start = 0;
	i = 0;
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checkset(s1[end -1], set))
		end--;
	new_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (start < end)
	{
		new_str[i] = s1[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// int main()
// {
//     char str[] = "MaMaria MariaMa";
//     char set[] = "Ma";
//     char *m = ft_strtrim(str, set);
//     printf("%s", m);
// }
