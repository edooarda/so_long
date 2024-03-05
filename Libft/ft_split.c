/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 10:42:31 by edribeir      #+#    #+#                 */
/*   Updated: 2023/10/30 17:11:52 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **array_str)
{
	int	word;

	word = 0;
	while (array_str[word])
	{
		free(array_str[word]);
		word++;
	}
	free(array_str);
	return (NULL);
}

static int	ft_get_words(char const *s, char c)
{
	unsigned int	words;
	int				i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	**create_array(char **array_str, char const *s, char c)
{
	int		wordstart;
	size_t	word_len;
	int		i;
	int		word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			wordstart = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			word_len = (size_t)(i - wordstart);
			array_str[word] = ft_substr(s, wordstart, word_len);
			if (array_str[word] == NULL)
				return (ft_free(array_str));
			word++;
		}
	}
	array_str[word] = NULL;
	return (array_str);
}

char	**ft_split(char const *s, char c)
{
	char	**array_str;

	if (s == NULL)
		return (NULL);
	array_str = (char **)malloc((ft_get_words(s, c) + 1) * sizeof(char *));
	if (array_str == NULL)
		return (NULL);
	array_str = create_array(array_str, s, c);
	if (array_str == NULL)
		return (NULL);
	return (array_str);
}

// int main()
// {
//     int i;
//     // char str[] = "";
//     char str[] = "Hello Human Coder";
//     char c = ' ';

//     i = 0;
//     // printf("%d\n", ft_get_words(str, c));
//     char **m = ft_split(str, c);
//     // if (ft_split(str, c) == NULL) //test when it is a null 
//     // {
//     //     printf("%s\n", "Null");
//     // }
//     while(m[i])
//     {
//         printf("%s\n", m[i]);
//         i++;
//     }
// }